rm -f MyStrategy.zip
zip MyStrategy.zip `ls *.cpp *.h *.hpp | egrep -v "RemoteProcessClient|Runner|Strategy.h"`
