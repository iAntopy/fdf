TESTER_PATH=$(pwd)
cd ..
ROOT_PATH=$(pwd)
cd src/mtx_math/opps_template
sh OPP_GENERATOR.sh re
cd $ROOT_PATH
make
