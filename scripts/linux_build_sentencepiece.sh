echo 'starting to build sentencepiece repo for Linux...'

cd ./sentencepiece
pwd

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

sudo ldconfig -v

echo 'finished building sentencepiece repo...'