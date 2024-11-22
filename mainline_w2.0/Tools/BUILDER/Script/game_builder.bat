set PATH=%DIR_TOOLS%;%PATH%
plink -pw %DEV_PASSWD% %DEV_USER%@%BUILD_SERVER% "./game_builder.sh %REVISION% %LOCALE%"
IF ERRORLEVEL 13 (
	echo "���� ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 12 (
	echo "������� ���� game_%LOCALE%" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 11 (
	echo "game_%LOCALE% ���� üũ ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 10 (
	echo "game_%LOCALE% ����� ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 9	(
	echo "game_%LOCALE% check out ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 8	(
	echo "game_%LOCALE% revert ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 7	(
	echo "��Ȯ�� ������ �ѹ� �������� ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 6	(
	echo "���� ���̳ʸ� ������ ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 5	(
	echo "���̺귯�� ������ ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 4	(
	echo "������ %REVISION% �ҽ� ���� ������Ʈ ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 3	(
	echo "���� �ҽ� revert ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 2	(
	echo "��ȿ���� ���� ���" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 1	(
	echo "�α��� ����" > ERROR.txt
	goto error_state
)
IF ERRORLEVEL 0 exit 0

:error_state

echo "---------------------------------" >> ERROR.txt
echo "            error log            " >> ERROR.txt
echo "---------------------------------" >> ERROR.txt

del ERROR_LOG.txt
%DIR_WinScp%\winscp %DEV_USER%:%DEV_PASSWD%@%BUILD_SERVER% /script=%DIR_SCRIPT%\get_error_log.txt

type ERROR_LOG.txt >> ERROR.txt

exit 1