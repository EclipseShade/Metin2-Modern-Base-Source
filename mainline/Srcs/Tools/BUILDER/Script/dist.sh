#!
REVISION=$1
LOCALE=$2
TARGET=$3

P4PORT=10.1.89.15:1901; export P4PORT
P4USER=BUILDER;            export P4USER
P4CLIENT=BUILDER-BSD;    export P4CLIENT
P4EDITOR=vim;           export P4EDITOR
P4CHARSET=utf8;         export P4CHARSET
P4PASSWD=dlalfmqlfej!;      export P4PASSWD

echo $P4PASSWD | p4 login

if [ ! $? -eq 0 ]; then
    exit 1
fi

if [ "$TARGET" == "ALL" ]; then
	rm -rf ~/metin2/dist/$LOCALE/Test/Server
	if [ "$REVISION" != "head" ]; then
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/...@$REVISION > ~/LOG.txt
	else
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/...#head > ~/LOG.txt
	fi
elif [ "$TARGET" == "LOCALE" ]; then
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/locale
	if [ "$REVISION" != "head" ]; then
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/locale/...@$REVISION > ~/LOG.txt
	else
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/locale/...#head > ~/LOG.txt
	fi
elif [ "$TARGET" == "PROTOS" ]; then
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/*_proto.txt
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/*_names.txt
	if [ "$REVISION" != "head" ]; then
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*_proto.txt@$REVISION > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*_names.txt@$REVISION > ~/LOG.txt
	else
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*_proto.txt#head > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*_names.txt#head > ~/LOG.txt
	fi
elif [ "$TARGET" == "BINARIES" ]; then
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/game_*
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/db_*
	if [ "$REVISION" != "head" ]; then
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/game_*@$REVISION > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/db_*@$REVISION > ~/LOG.txt
	else
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/game_*#head > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/db_*#head > ~/LOG.txt
	fi
elif [ "$TARGET" == "SECURITIES" ]; then
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/*.CS3
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/panama
	rm -rf ~/metin2/dist/$LOCALE/Test/Server/package
	if [ "$REVISION" != "head" ]; then
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*.CS3@$REVISION > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/panama/...@$REVISION > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/package/...@$REVISION > ~/LOG.txt
	else
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/*.CS3#head > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/panama/...#head > ~/LOG.txt
		p4 sync -f //metin2/dist/$LOCALE/Test/Server/package/...#head > ~/LOG.txt
	fi
fi

if [ ! $? -eq 0 ]; then
	cat ~/LOG.txt
    exit 2
fi

PWD=`pwd`
case "$LOCALE" in
	ca)
		LOC=canada
		;;
	br)
		LOC=brazil
		;;
	tw)
		LOC=taiwan
		;;
	ymir)
		LOC=ymir
		;;
	we_korea)
		LOC=we_korea
		;;
	*)
		echo "LOCALE : ca, br, tw, ymir, we_korea"
		exit 3
		;;
esac

if [[ "$TARGET" == "ALL" ||  "$TARGET" == "LOCALE" ]]; then
	cd ~/metin2/dist/$LOCALE/Test/Server/locale/$LOC/quest
	chmod +x make_quest
	chmod +x qc
	./make_quest > ~/LOG.txt
fi

if [ ! $? -eq 0 ]; then
	cat ~/LOG.txt
    exit 4
fi

cd $PWD

DATE=`date "+%Y-%m-%d-%H-%M"`
NEW_NAME=Server_"$LOCALE"_"$TARGET"_$DATE
cd ~/metin2/dist/$LOCALE/Test
mv Server $NEW_NAME

if [ "$TARGET" == "ALL" ]; then
	tar cvf $NEW_NAME.tar $NEW_NAME/ ~/LOG.txt
elif [ "$TARGET" == "LOCALE" ]; then
	tar cvf $NEW_NAME.tar $NEW_NAME/locale/ > ~/LOG.txt
elif [ "$TARGET" == "PROTOS" ]; then
	tar cvf $NEW_NAME.tar $NEW_NAME/*_proto.txt $NEW_NAME/*_names.txt > ~/LOG.txt
elif [ "$TARGET" == "BINARIES" ]; then
	tar cvf $NEW_NAME.tar $NEW_NAME/game_* $NEW_NAME/db_* > ~/LOG.txt
elif [ "$TARGET" == "SECURITIES" ]; then
	tar cvf $NEW_NAME.tar $NEW_NAME/panama $NEW_NAME/package $NEW_NAME/*.CS3 > ~/LOG.txt
fi

mv $NEW_NAME.tar $PWD
mv $NEW_NAME Server
cd $PWD
scp $NEW_NAME.tar metin2@202.31.212.73:
case "$LOCALE" in
	ca)
		ssh -t metin2@202.31.212.73 "cd ~/dist;./scp.sh ca ~/$NEW_NAME.tar;if [ ! \$? -eq 0 ]; then exit 5;fi;rm -rf ~/$NEW_NAME.tar"
		;;
	br)
		ssh -t metin2@202.31.212.73 "~/dist/script/dist_brazil.sh $NEW_NAME.tar;if [ ! \$? -eq 0 ]; then exit 5;fi;rm -rf ~/$NEW_NAME.tar"
		;;
	tw)
		#ssh -t metin2@202.31.212.73 "cd ~/dist;./scp.sh tw ~/$NEW_NAME.tar;if [ ! \$? -eq 0 ]; then exit 5;fi;rm -rf ~/$NEW_NAME.tar"
		;;
	ymir)
		;;
	we_korea)
		;;
	*)
		echo "LOCALE : ca, br, tw, ymir, we_korea"
		;;
esac
rm -rf $NEW_NAME.tar
cat ~/LOG.txt
exit 0
