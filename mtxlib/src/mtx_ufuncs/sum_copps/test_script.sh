if [ $(ls -l | grep '__BASE_ZZZ' | wc -l) = 2 ];
then
	echo 'cactus au bonheur' 
else
	echo 'cactus au pustules'
fi
