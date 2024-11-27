#! /usr/local/bin/python3

"""PreQC Details
1) In:
	define __smth__ "a b c d"
 But not in:
	define __smth__ "a\32b\32c\32d"
 The space is not valid and only '"a' will be "used" to replace (bug!)
2) define will replace everything containing that 'token'
 except for:
 a) compound words:
	schu__smth__re
 b) or inside "" strings: (es.)
	say(" __smth__ ")
 d) or with nothing before: (nothing or seps)
		__smth__
 d) or comment:
	-- __smth__
 e) but not for: (bug!)
	--[[
	__smth__]]
3) The define 'token' should stay before any 'quest'
define __smth__ something
"""

import os
import shutil
import time

QUESTLIST_PATH_DFT="./quest_list"
WORKINGPATH_DFT="./.pre_qc"
COPYALL_DFT=False
VERBOSITY_DFT=False
BACKUP_DFT=False
SINGLEFILE_DFT=""
TOKEN_LIST = ("\t", ",", " ", "=", "[", "]","-","<",">","~","!",".","(",")","+","*","/","\n","\r")

def cmp(a, b):
	return (a > b) - (a < b)

#if py>=2.4 use @BenchMe instead of BenchMe(fnc, (args), {args)
def BenchMe(fnc, *args, **kw):
	print("--- BenchMe calling for {} with args {}, {} Begin ---".format(fnc.__name__, args, kw))
	t_start = time.time()
	rtn = fnc(*args, **kw)
	print(time.time()-t_start)
	print("--- BenchMe for {} End ---".format(fnc.__name__))
	return rtn
#(NoBenchMe,BenchMe)[verbosity] just for curiosity
def NoBenchMe(fnc, *args, **kw):
	return fnc(*args, **kw)

class PreQC(object):
	def __init__(self, questlistpath=QUESTLIST_PATH_DFT, workingpath=WORKINGPATH_DFT, verbosity=VERBOSITY_DFT, backup=BACKUP_DFT, copyall=COPYALL_DFT, singlefile=SINGLEFILE_DFT):
		self.questlistpath = questlistpath
		self.workingpath = workingpath
		self.verbosity = verbosity
		self.backup = backup
		self.copyall = copyall
		self.singlefile = singlefile
		self.benchFunc = (NoBenchMe,BenchMe)[verbosity]
		if not os.path.exists(self.workingpath):
			os.makedirs(self.workingpath)
		else:
			#security
			if (not self.workingpath[0]=="/") or (self.workingpath.find("..")==-1) or (self.workingpath=="."):
				shutil.rmtree(self.workingpath)
				os.makedirs(self.workingpath)
		self.lista = []
		if self.copyall or not self.singlefile:
			self.benchFunc(self.LoadList)
		else:
			self.lista.append(self.singlefile)

	def LoadList(self):
		with open(self.questlistpath, "r", encoding="ascii", errors="surrogateescape") as f:
			for fname in f.readlines():
				fname = fname.rstrip()
				if not fname or fname[0]=="#":
					continue
				self.lista.append(fname)
			if self.verbosity:
				print("--- PreQC.LoadList Begin ---")
				for ffname in self.lista: print(repr(ffname))
				print("--- PreQC.LoadList End ---")

	def Generate(self):
		for fname in self.lista:
			self.benchFunc(Run, *(fname, self.workingpath, self.copyall))

	def Compile(self):
		if os.path.exists("object"):
			if self.backup:
				os.rename("object", "object__{}".format(time.strftime("%Y%m%d-%H%M%S", time.localtime())))
			shutil.rmtree("./object")
		#iter quest list
		for fname in self.lista:
			if not fname:
				continue
			#no popen for convenience
			if "/" in fname:
				#fix bug if .quest paths contain /
				#you should not call two quests with the same name anyway
				fname=fname.split("/")[-1]
			retcode = os.system("./qc {}/{}".format(self.workingpath, fname))
			if retcode:
				print("Error {} occured on quest {}/{}".format(retcode, self.workingpath, fname))
				os._exit(0)
		os.system("chmod -R ug+rwx object")

def split_by_quat(buf):
	p = False
	l = list(buf)
	l.reverse()
	s = ""
	res = []
	while l:
		c = l.pop()
		if c == '"':
			if p == True:
				s += c
				res += [s]
				s = ""
			else:
				if len(s) != 0:
					res += [s]
				s = '"'
			p = not p
		elif c == "\\" and l[0] == '"':
			s += c
			s += l.pop()
		else:
			s += c

	if len(s) != 0:
		res += [s]
	return res

def AddSepMiddleOfElement(l, sep):
	l.reverse()
	new_list = [l.pop()]
	while l:
		new_list.append(sep)
		new_list.append(l.pop())
	return new_list

def my_split_with_seps(s, seps):
	res = [s]
	for sep in seps:
		new_res = []
		for r in res:
			sp = r.split(sep)
			sp = AddSepMiddleOfElement(sp, sep)
			new_res += sp
		res = new_res
	new_res = []
	for r in res:
		if r != "":
			new_res.append(r)
	return new_res

def my_split(s, seps):
	res = [s]
	for sep in seps:
		new_res = []
		for r in res:
			sp = r.split(sep)
			new_res += sp
		res = new_res
	new_res = []
	for r in res:
		if r != "":
			new_res.append(r)
	return new_res
def MultiIndex(list, key):
	l = []
	i = 0
	for s in list:
		if s == key:
			l.append(i)
		i = i + 1
	return l

def Replace(lines, parameter_table, keys):
	r = []
	for string in lines:
		l = split_by_quat(string)
		for s in l:
			if s[0] == '"':
				r += [s]
			else:
				tokens = my_split_with_seps(s, TOKEN_LIST)
				for key in keys:
					try:
						indices = MultiIndex(tokens, key)
						for i in indices:
							tokens[i] = parameter_table[key][0]
					except:
						pass
				r += tokens
	return r

def MakeParameterTable(lines, parameter_table, keys):
	names = []
	values = []
	group_names = []
	group_values = []
	idx = 0
	for line in lines:
		idx += 1
		line = line.rstrip()
		if -1 != line.find("--"):
			line = line[0:line.find("--")]

		tokens = my_split(line, ["\t", ",", " ", "=", "[", "]", "\r", "\n"])
		if len(tokens) == 0:
			continue
		if cmp(tokens[0], "quest") == 0:
			start = idx
			break
		if cmp(tokens[0], "define") == 0:
			if cmp(tokens[1], "group") == 0:
				group_value = []
				for value in tokens[3:]:
					if parameter_table.get(value, 0) != 0:
						value = parameter_table[value]
					group_value.append(value)
				parameter_table[tokens[2]] = group_value
				keys.append(tokens[2])
			elif len(tokens) > 5:
				print("{} Invalid syntax".format(idx))
				print("define [name] = [value]")
				print('define group [name] = "["[v0],[v1], ... "]"')
			else:
				value = tokens[2]
				if parameter_table.get(value, 0) != 0:
					value = parameter_table[value]
				parameter_table[tokens[1]] = [value]
				keys.append(tokens[1])
	parameter_table = dict(list(zip(group_names, group_values)))
	return start

def Run(inputFN=SINGLEFILE_DFT, workingpath=WORKINGPATH_DFT, copyall=COPYALL_DFT):
	parameter_table = {}
	keys = []
	if not inputFN:
		return False

	with open(inputFN, encoding="ascii", errors="surrogateescape") as fname:
		lines = fname.readlines()
		start = MakeParameterTable(lines, parameter_table, keys)
		outputFN = "{}/{}".format(workingpath, inputFN.split("/")[-1])

		if not len(keys) == 0:
			lines = lines [start-1:]
			r = Replace(lines, parameter_table, keys)
			# dump
			with open(outputFN, "w", encoding="ascii", errors="surrogateescape") as f:
				f.writelines(r)
		elif copyall:
			shutil.copyfile(inputFN, outputFN)
	return True

if __name__ == "__main__":
	def Usage():
		print("""Usage:
	--help or -h to show this message
	--lpath	or -l to select the quest_list file path (./quest_list by default)
	--epath or -e to select the working folder path (./pre_qc by default)
	--all or -a to copy to pre_qc folder all the quests even they have no define tokens
	--compile or -c to automatically run ./qc for each quest (False by default)
	--nopre or -n to just read the list without start processing (False by default)
	--verbose or -v to enable verbosity (False by default)
	--backup or -b to perform a backup of object (False by default)
	--file or -f to compile a single quest file
	# ./pre_qc.py
	# ./pre_qc.py -cf game_option.quest
	# ./pre_qc.py -l quest_list -e pre_qc
	# ./pre_qc.py -l ./muhsecret/quest_list -e ./foldername/pre_qc
	# ./pre_qc.py -ac
	# ./pre_qc.py -bv
""")
	import getopt
	import os
	import sys
	try:
		# grab args
		optlist, args = getopt.getopt(sys.argv[1:], "hl:e:acnvbf:", ("help","lpath","epath","all","compile","nopre","verbose","backup","file"))
		# config
		v_bcomp = False
		v_bnpre = False
		v_copyall = COPYALL_DFT
		v_questlistpath = QUESTLIST_PATH_DFT
		v_workingpath = WORKINGPATH_DFT
		v_verbosity = VERBOSITY_DFT
		v_backup = BACKUP_DFT
		v_singlefile = ''
		# analyze args
		for o, a in optlist:
			if o in ("-h", "--help"):
				sys.exit(Usage())
			if o in ("-l", "--lpath"):
				v_questlistpath = a
			elif o in ("-e", "--epath"):
				v_workingpath = a
			elif o in ("-a", "--all"):
				v_copyall = True
			elif o in ("-c", "--compile"):
				v_bcomp = True
			elif o in ("-n", "--nopre"):
				v_bnpre = True
			elif o in ("-v", "--verbose"):
				v_verbosity = True
			elif o in ("-b", "--backup"):
				v_backup = True
			elif o in ("-f", "--file"):
				v_singlefile = a
			else:
				sys.exit(Usage())
		# check
		if (not v_questlistpath) or (not v_workingpath):
			sys.exit(Usage())
		# start
		pQC = PreQC(questlistpath=v_questlistpath, workingpath=v_workingpath, verbosity=v_verbosity, backup=v_backup, copyall=v_copyall, singlefile=v_singlefile)
		if not v_bnpre:
			pQC.benchFunc(pQC.Generate)
		if v_bcomp:
			pQC.benchFunc(pQC.Compile)
	except getopt.GetoptError as err:
		sys.exit(err)
