#!/usr/local/bin/python3
import fnmatch
import os
import pathlib
import shutil
import time
from gen_settings import *

portlist={}
clearlist=[]
startlist=[]
serverinfolist=[]

def IsWindows():
	return v_system=="Windows"

def IsLinuxOrBSD():
	return v_system in ("FreeBSD", "Linux")

def SlashFix(pathname):
	if v_system in ("FreeBSD", "Linux"):
		return pathname.replace("\\", "/")
	elif v_system=="Windows":
		return pathname.replace("/", "\\")
	return pathname

def EscapeString(txt):
	if v_system in ("FreeBSD", "Linux"):
		txt = txt.replace('"', '\\\"')
	return txt

def DeleteFilesVerbose(file_list):
	for pattern in file_list:
		if "*" in pattern:
			for filename in os.listdir('.'):
				if fnmatch.fnmatch(filename, pattern):
					if os.path.exists(filename):
						os.remove(filename)
						print(filename)
		else:
			if os.path.exists(pattern):
				os.remove(pattern)
				print(pattern)

def ClearFolder(folder_path):
	for filename in os.listdir(folder_path):
		file_path = os.path.join(folder_path, filename)
		try:
			if os.path.isfile(file_path) or os.path.islink(file_path):
				os.unlink(file_path)
			elif os.path.isdir(file_path):
				shutil.rmtree(file_path)
		except Exception as e:
			print("Failed to delete {}. Reason: {}".format(file_path, e))

def CreateFolder(foldername):
	os.makedirs(foldername, exist_ok=True)

def CreateEmptyFile(file_path, overwrite = True):
	if not overwrite and os.path.exists(file_path):
		return
	with open(file_path, 'w'):
		pass

def TouchFile(file_path):
	try:
		with open(file_path, 'a'):
			os.utime(file_path, None)
	except OSError:
		pass

def Append2File(text, file_path):
	with open(file_path, 'a') as f:
		f.write(text)
		f.write('\n')

def DeleteFolder(path):
	shutil.rmtree(path)

def SymLinkCreate(src, dst, is_file):
	src = SlashFix(src)
	dst = SlashFix(dst)
	if v_system=="FreeBSD":
		fShell("ln -Ffnsw {} {}".format(src, dst))
	elif v_system=="Linux":
		fShell("ln -Ffns {}".format(src, dst))
	elif v_system=="Windows":
		if is_file:
			fShell("mklink {} {}".format(dst, src))
		else:
			fShell("mklink /D {} {}".format(dst, src))

def SymLinkCreateDir(src, dst):
	SymLinkCreate(src, dst, is_file=False)

def SymLinkCreateFile(src, dst):
	SymLinkCreate(src, dst, is_file=True)

def SymLinkCreateFileExe(src, dst):
	if v_system=="Windows":
		src+=".exe"
		dst+=".exe"
	SymLinkCreate(src, dst, is_file=True)

def WriteHostConfig(szConfFile, szGameName):
	Append2File("HOSTNAME: {}".format(szGameName), szConfFile)

def WriteChannelConfig(szConfFile, dwChannel):
	if dwChannel==M2TYPE.NOCHAN:
		dwChannel=1
	Append2File("CHANNEL: {}".format(dwChannel), szConfFile)

def WriteMapConfig(szConfFile, szMapList):
	if len(szMapList.split())>=32:
		print("WARNING: MORE THAN 32 MAPS INSIDE: {}".format(szConfFile))
	Append2File("MAP_ALLOW: {}".format(szMapList), szConfFile)

def WritePortConfig(szConfFile, wGenPort, dwType, dwPortType=None):
    if dwType == M2TYPE.DB:
        Append2File("{} = {}".format(PORT.lPORT[PORT.BIND_PORT], wGenPort), szConfFile)
    elif dwType == M2TYPE.CORE or dwType == M2TYPE.AUTH:
        Append2File("{}: {}".format(PORT.lPORT[dwPortType], wGenPort), szConfFile)

def genWriteConfig(szConfFile, tuSubConfTable):
	for val1 in tuSubConfTable:
		try:
			if isinstance(val1[1], (list, tuple)):
				configValue = val1[0].format(*val1[1])
			else:
				configValue = val1[0].format(val1[1])
		except IndexError:
			print(repr(val1))
			raise IndexError
		#skip test server in ch1
		if DISABLE_TEST_MODE_IN_CH1 and configValue.strip()=="TEST_SERVER: 1" and "/ch1/" in szConfFile:
			continue

		try:
			Append2File("{}".format(configValue), szConfFile)
		except TypeError:
			print("WARNING: WRONG CONFIG OPTION FORMAT: {}".format(val1))

def genMakeConfig(szConfFile, diConfTable, bIsExtra=False, dwType=None):
	genWriteConfig(szConfFile, diConfTable["general"])
	if bIsExtra:
		genWriteConfig(szConfFile, diConfTable["extra"])
	if dwType!=None:
		genWriteConfig(szConfFile, diConfTable[dwType])

def genGetRandPort(dwType):
	wTmpPort = PORT.RANDOMI
	while(True):
		if wTmpPort in portlist:
			wTmpPort+=1
			continue
		else:
			portlist[wTmpPort]=dwType
			break
	return wTmpPort

def genGenM2List():
	from json import dumps as j_dumps
	startFilename = "start.list"
	clearFilename = "clear.list"
	with open(startFilename, "w") as fList: # b for Unix end line
		fList.write(j_dumps(startlist, indent=4))
	with open(clearFilename, "w") as fList: # b for Unix end line
		fList.write(j_dumps(clearlist, indent=4))
	print("Generated starting files {} {}".format(startFilename, clearFilename))

def genGenIpfwList():
	def Joi(mList):
		return ' '.join(str(v) for v in mList)
	szRules=CustIpfwList.format(udp_allowed_ports=Joi(udp_yes_ports), tcp_allowed_ports=Joi(tcp_yes_ports), tcp_blocked_ports=Joi(tcp_nop_ports))
	filename = "ipfw.rules"
	with open(filename, "w") as fIpfw: #b for unix end line
		fIpfw.write(szRules)
	print("Generated IPFW rules inside {}".format(filename))

def genGenServerInfo():
	def calcPortList():
		_portlist={}
		_pickedchannels={}
		_pickedauths={}
		for elem in serverinfolist:
			if elem["type"]==M2TYPE.AUTH:
				newpath = elem["path"].replace("/", "-")
				_portlist[newpath] = elem["port"]
				_pickedauths[newpath] = elem
			elif elem["type"]==M2TYPE.CORE:
				if elem["chan"] == 99:
					continue
				newpath = "ch{}".format(elem["chan"])
				if newpath not in _portlist:
					_portlist[newpath] = elem["port"]
					_pickedchannels[newpath] = elem

		_portlistSTR = ""
		for elem in _portlist:
			_portlistSTR += '\t"{}":{},\n'.format(elem, _portlist[elem])
		return _portlist,_portlistSTR,_pickedchannels,_pickedauths
	(portlist,portlistSTR,pickedchannels,pickedauths) = calcPortList()

	def calcChannelDict():
		_channelDictSTR = ""
		for elem in pickedchannels:
			chan = pickedchannels[elem]["chan"]
			serverID = 1
			chanID = chan - 1
			keyID = serverID * 10 + chanID
			chanName = "CH-{}".format(chan)
			_channelDictSTR += '\t{chanID}: {{"key":{keyID}, "name":TextColor("{chanName}", "FFffFF"), "ip":SRV1["host"], "tcp_port":SRV1["{elem}"], "udp_port":SRV1["{elem}"], "state":STATE_NONE,}},\n'.format(
				chanID=chanID, keyID=keyID, chanName=chanName, elem=elem
			)
		return _channelDictSTR
	channelDictSTR = calcChannelDict()

	def calcAuthDict():
		_authDictSTR = ""
		ENABLE_RANDOM_AUTH = True
		if ENABLE_RANDOM_AUTH:
			for elem in pickedchannels:
				chan = pickedchannels[elem]["chan"]
				chanID = chan
				_authDictSTR += '\t\t{chanID}: {{"ip": SRV1["host"], "port": get_item_from_list(SRV1["authlist"]),}},\n'.format(
					chanID=chanID
				)
		else:
			_firstauth = next(iter(pickedauths))
			for elem in pickedchannels:
				chan = pickedchannels[elem]["chan"]
				chanID = chan - 1
				_authDictSTR += '\t\t{chanID}: {{"ip": SRV1["host"], "port": SRV1["{_firstauth}"],}},\n'.format(
					chanID=chanID, _firstauth=_firstauth
				)
		return _authDictSTR
	authDictSTR = calcAuthDict()

	def calcAuthList():
		_authListSTR = ""
		for elem in pickedauths:
			_authListSTR += "{},".format(pickedauths[elem]['port'])
		return _authListSTR
	authListSTR = calcAuthList()

	# print("authListSTR:\n", authListSTR)
	# print("portlistSTR:\n", portlistSTR)
	# print("channelDictSTR:\n", channelDictSTR)
	# print("authDictSTR:\n", authDictSTR)
	hostnameSTR = "127.0.0.1"

	filename = "serverinfo.py"
	with open(filename, "w") as fSI: #b for unix end line
		fSI.write(CustServerInfo.format(
			hostname=hostnameSTR,
			portlist=portlistSTR,
			channel_dict=channelDictSTR,
			auth_dict=authDictSTR,
			authlist=authListSTR
		))
	print("Generated serverinfo details inside {}".format(filename))

def genInit():
	# clean port list
	global portlist
	portlist.clear()
	# clean start/clear list
	global startlist, clearlist
	del startlist[:]
	del clearlist[:]
	# clean ipfw list
	global udp_yes_ports,tcp_yes_ports,tcp_nop_ports
	del udp_yes_ports[:]
	del tcp_yes_ports[:]
	del tcp_nop_ports[:]

def genInitSrv(szSvr):
	#
#	for val1 in ("share/data","share/locale","share/package","share/panama","share/conf","share/bin"):
	for val1 in ("data","data/package","data/panama", "data/map", "data/monster", "data/pc", "data/pc2", "data/pc3", "data/quest"):
		CreateFolder("%s/%s"%(szSvr, val1))
		# print "%s/%s"%(szSvr, val1)
	#
#	for val1 in ("share/conf/BANIP","share/conf/CMD","share/conf/CRC","share/conf/VERSION","share/conf/state_user_count","share/bin/db","share/bin/game"):
#		TouchFile("%s/%s" % (szSvr, val1))
		# print "%s/%s"%(szSvr, val1)
	#
#	for val1 in ("data/blend.txt","data/common_drop_item.txt", "data/cube.txt", "data/dragon_soul_table.txt", 
#				"data/drop_item_group.txt", "data/etc_drop_item.txt", "data/forkedmapindex.txt", "data/group.txt", 
#				"data/group_group.txt", "data/mob_drop_item.txt", "data/special_item_group.txt", 
#				"data/BlueDragon.lua", "data/settings.lua", "data/translate.lua"):
#		TouchFile("%s/%s" % (szSvr, val1))
		# print "%s/%s"%(szSvr, val1)
#global single server rules
genConfig = {}
genConfig["all"] = {}
#for ipfw rules
udp_yes_ports=[]
tcp_yes_ports=[]
tcp_nop_ports=[]

def genCalcParentRet(szParentName):
	return szParentName.count("/")*v_chanPath

def genMain(oSub={}, szParentName=[]):
	global genConfig
	global startlist, clearlist
	global udp_yes_ports, tcp_yes_ports, tcp_nop_ports
	global serverinfolist
	if not oSub:
		oSub=M2S
		genInit()
	for v1 in oSub:
		k1=v1["name"]
		listTmpParentName=list(szParentName)	# list() to bypass variable passed by reference to value
		listTmpParentName.append(k1)
		szTmpParentName=("/".join(listTmpParentName))
		# DeleteFolder("%s" % szTmpParentName) # completely unsafe
		CreateFolder("%s" % szTmpParentName)
		# print szTmpParentName
		if v1["type"]==M2TYPE.DB:
			k1s=genConfig["active"]
			#logs make paths
			CreateFolder("%s/%s/%s/cores" % (k1s, v_logFolder, szTmpParentName))
			CreateFolder("%s/%s/%s/log" % (k1s, v_logFolder, szTmpParentName))
			TouchFile("%s/%s/%s/PTS" % (k1s, v_logFolder, szTmpParentName))
			#logs sym paths
			SymLinkCreateDir("../%s/%s/cores" % (v_logFolder, szTmpParentName), "%s/log" % (szTmpParentName))
			SymLinkCreateDir("../%s/%s/log" % (v_logFolder, szTmpParentName), "%s/log" % (szTmpParentName))
			SymLinkCreateFile("../%s/%s/PTS" % (v_logFolder, szTmpParentName), "%s/PTS" % (szTmpParentName))
			szDbName="%s-%s"%(genConfig["active"], k1)
			SymLinkCreateFileExe("db", "%s/%s" % (szTmpParentName,szDbName))
			if IsWindows():
				SymLinkCreateFile("../share/bin/libmysql.dll", "%s/libmysql.dll" % (szTmpParentName))
			#start/logs track
			startlist.append(
				{
					"path":szTmpParentName,
					"name":szDbName,
					"type":M2TYPE.DB,
					"chan":M2TYPE.NOCHAN,
					"serv":genConfig["active"],
				}
			)
			clearlist.append(
				{
					"path":"%s/%s/%s"%(k1s, v_logFolder, szTmpParentName),
					"type":M2TYPE.DB,
					"chan":M2TYPE.NOCHAN,
					"serv":genConfig["active"],
				}
			)
			#@item/mob protos .txt
#			SymLinkCreateFile("../data/item_names.txt", "%s/item_names.txt" % (szTmpParentName))
#			SymLinkCreateFile("../data/item_proto.txt", "%s/item_proto.txt" % (szTmpParentName))
#			SymLinkCreateFile("../data/mob_names.txt", "%s/mob_names.txt" % (szTmpParentName))
#			SymLinkCreateFile("../data/mob_proto.txt", "%s/mob_proto.txt" % (szTmpParentName))
			#@CONFIG details
			CreateEmptyFile("%s/conf.txt"%(szTmpParentName))
			genMakeConfig("%s/conf.txt"%szTmpParentName, v1["config"], genConfig["all"][genConfig["active"]]["isextra"])
			try:
				genConfig["all"][genConfig["active"]]["db_port"]=M2PORTS[szDbName]
			except KeyError:
				genConfig["all"][genConfig["active"]]["db_port"]=genGetRandPort(v1["type"])
			WritePortConfig("%s/conf.txt"%szTmpParentName, genConfig["all"][genConfig["active"]]["db_port"], v1["type"], PORT.BIND_PORT)
			#add to ipfw rules
			tcp_nop_ports.append(genConfig["all"][genConfig["active"]]["db_port"])
		elif v1["type"]==M2TYPE.CHANFOLDER or v1["type"]==M2TYPE.CHANNEL:
			if v1["type"]==M2TYPE.CHANNEL:
				genConfig["all"][genConfig["active"]]["chan"]=v1["chan"]
			if v1["type"]==M2TYPE.CHANFOLDER:
				genConfig["all"][genConfig["active"]]["mark"]="%s/mark"%szTmpParentName
				CreateFolder("%s" % genConfig["all"][genConfig["active"]]["mark"])
			genMain(v1["sub"], listTmpParentName)
		elif v1["type"]==M2TYPE.SERVER:
			genInitSrv(szTmpParentName)
			genConfig["active"]=v1["name"]
			genConfig["all"][v1["name"]]={}
			genConfig["all"][v1["name"]]["isextra"]=v1["isextra"]
			genConfig["all"][v1["name"]]["mark"]="%s/mark"%szTmpParentName
			genMain(v1["sub"], listTmpParentName)
		elif v1["type"]==M2TYPE.AUTH or v1["type"]==M2TYPE.CORE:
			k1s=genConfig["active"]
			#logs make paths
			CreateFolder("%s/%s/%s/auth" % (k1s, v_logFolder, szTmpParentName))
			CreateFolder("%s/%s/%s/log" % (k1s, v_logFolder, szTmpParentName))
			TouchFile("%s/%s/%s/PTS" % (k1s, v_logFolder, szTmpParentName))
			#logs sym paths
			gCPR=genCalcParentRet(szTmpParentName)
			SymLinkCreateDir("%s%s/%s/cores" % (gCPR,v_logFolder,szTmpParentName), "%s/cores" % (szTmpParentName))
			SymLinkCreateDir("%s%s/%s/log" % (gCPR,v_logFolder,szTmpParentName), "%s/log" % (szTmpParentName))
			SymLinkCreateFile("%s%s/%s/PTS" % (gCPR,v_logFolder,szTmpParentName), "%s/PTS" % (szTmpParentName))
			#dirs sym paths
			SymLinkCreateDir("%sdata" % (gCPR), "%s/data" % (szTmpParentName))
#			SymLinkCreateDir("%sshare/locale" % (gCPR), "%s/locale" % (szTmpParentName))
			SymLinkCreateDir("%sdata/package" % (gCPR), "%s/package" % (szTmpParentName))
			SymLinkCreateDir("%sdata/panama" % (gCPR), "%s/panama" % (szTmpParentName))
			#files sym paths
#			SymLinkCreateFile("%sshare/conf/CMD" % (gCPR), "%s/CMD" % (szTmpParentName))
#			SymLinkCreateFile("%sshare/conf/CRC" % (gCPR), "%s/CRC" % (szTmpParentName))
#			SymLinkCreateFile("%sshare/conf/VERSION" % (gCPR), "%s/VERSION" % (szTmpParentName))
#			SymLinkCreateFile("%sshare/conf/state_user_count" % (gCPR), "%s/state_user_count" % (szTmpParentName))
			if v1["type"]==M2TYPE.AUTH:
				SymLinkCreateFile("%sshare/conf/BANIP" % (gCPR), "%s/BANIP" % (szTmpParentName))
			if v1["type"]==M2TYPE.AUTH:
				szGameName="%s-%s"%(genConfig["active"], k1)
			else:
				szGameName="%s-ch%u-%s"%(genConfig["active"], genConfig["all"][genConfig["active"]]["chan"], k1)
			#mark sym path
			if v1["type"]==M2TYPE.CORE:
				gCPR2=genCalcParentRet(genConfig["all"][genConfig["active"]]["mark"])
				SymLinkCreateDir("%smark" % gCPR2, "%s/mark" % (szTmpParentName))
			#core sym path
			SymLinkCreateFileExe("%sdb/game" % (gCPR), "%s/%s" % (szTmpParentName, szGameName))
			if IsWindows():
				SymLinkCreateFile("%sshare/bin/libmysql.dll" % (gCPR), "%s/libmysql.dll" % (szTmpParentName))
				SymLinkCreateFile("%sshare/bin/DeviL-1.7.8.dll" % (gCPR), "%s/DeviL-1.7.8.dll" % (szTmpParentName))
				SymLinkCreateFile("%sshare/bin/DeviL-1.7.8d.dll" % (gCPR), "%s/DeviL-1.7.8d.dll" % (szTmpParentName))
			#start/logs track
			if v1["type"]==M2TYPE.AUTH:
				kh1=M2TYPE.NOCHAN
			else:
				kh1=genConfig["all"][genConfig["active"]]["chan"]
			startlist.append(
				{
					"path":szTmpParentName,
					"name":szGameName,
					"type":v1["type"],
					"chan":kh1,
					"serv":genConfig["active"],
				}
			)
			clearlist.append(
				{
					"path":"%s/%s/%s"%(k1s, v_logFolder, szTmpParentName),
					"type":v1["type"],
					"chan":kh1,
					"serv":genConfig["active"],
				}
			)
			#@CONFIG details
			CreateEmptyFile("%s/CONFIG" % (szTmpParentName))
			genMakeConfig("%s/CONFIG"%szTmpParentName, v1["config"], genConfig["all"][genConfig["active"]]["isextra"], v1["type"])
			WriteHostConfig("%s/CONFIG"%szTmpParentName, szGameName)
			WriteChannelConfig("%s/CONFIG"%szTmpParentName, kh1)
			if not v1["type"]==M2TYPE.AUTH:
				WriteMapConfig("%s/CONFIG"%szTmpParentName, v1["maps"])
			# w/o array, only if
			wTmpPort={}
			# PORT process
			try:
				wTmpPort[PORT.PORT]=M2PORTS[szGameName][0]
			except KeyError:
				wTmpPort[PORT.PORT]=genGetRandPort(v1["type"])
			WritePortConfig("%s/CONFIG"%szTmpParentName, wTmpPort[PORT.PORT], v1["type"], PORT.PORT)
			# P2P_PORT process
			try:
				wTmpPort[PORT.P2P_PORT]=M2PORTS[szGameName][1]
			except KeyError:
				wTmpPort[PORT.P2P_PORT]=genGetRandPort(v1["type"])
			WritePortConfig("%s/CONFIG"%szTmpParentName, wTmpPort[PORT.P2P_PORT], v1["type"], PORT.P2P_PORT)
			# DB_PORT process
			wTmpPort[PORT.DB_PORT]=genConfig["all"][genConfig["active"]]["db_port"]
			WritePortConfig("%s/CONFIG"%szTmpParentName, wTmpPort[PORT.DB_PORT], v1["type"], PORT.DB_PORT)
			#add to ipfw rules
			if v1["type"]==M2TYPE.AUTH:
				udp_yes_ports.append(wTmpPort[PORT.PORT])
			tcp_yes_ports.append(wTmpPort[PORT.PORT])
			tcp_nop_ports.append(wTmpPort[PORT.P2P_PORT])
			#add to serverinfo
			serverinfolist.append(
				{
					"path":szTmpParentName,
					"port":wTmpPort[PORT.PORT],
					"type":v1["type"],
					"chan":kh1,
					"serv":genConfig["active"],
				}
			)
		else:
			print("unrecognized type %u"%v1["type"])
	#end

def genList(bIsVerbose=False):
	if bIsVerbose:
		print("startlist:")
		for i in startlist:
			print("---", i, "---")
		print("clearlist:")
		for i in clearlist:
			print("---", i, "---")
		print("udp_yes_ports:")
		for i in udp_yes_ports:
			print("---", i, "---")
		print("tcp_yes_ports:")
		for i in tcp_yes_ports:
			print("---", i, "---")
		print("tcp_nop_ports:")
		for i in tcp_nop_ports:
			print("---", i, "---")
	genGenM2List()
	genGenIpfwList()
	genGenServerInfo()

def genGen():
	genMain()
	genList(True)


if __name__ == "__main__":
	genGen()
#



