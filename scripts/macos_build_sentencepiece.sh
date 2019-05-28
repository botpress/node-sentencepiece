echo 'starting to build sentencepiece repo for macOS...'

cd ./sentencepiece

echo 'pulling changes...'
git pull

dir=build
if [ ! -e $dir ]
then
    echo "creating $dir directory"
    mkdir $dir
else
    echo "$dir directory already exists"
fi

cd $dir
cmake ..
make -j $(nproc)
sudo make install

sudo update_dyld_shared_cache

bin_dir=bin
echo 'finished building sentencepiece repo. Copying library to bin directory...'
cd ../../

if [ ! -e $bin_dir ]
then
    echo "creating $bin_dir directory"
    mkdir $bin_dir
else
    echo "$bin_dir directory already exists"
fi
cp ./sentencepiece/build/src/libsentencepiece.a ./$bin_dir/sentencepiece_lib.lib

echo 'done.'