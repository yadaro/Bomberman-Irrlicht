wget https://netix.dl.sourceforge.net/project/irrlicht/Irrlicht%20SDK/1.8/1.8.4/irrlicht-1.8.4.zip
unzip irrlicht-1.8.4.zip
sudo apt-get install build-essential autoconf libtool libdevil-dev libfreeimage-dev libfreetype6-dev libglew1.5-dev libxaw7-dev libxrandr-dev libxt-dev libxxf86vm-dev libzzip-dev libirrlicht1.8 libirrlicht-dev libirrlicht-doc subversion build-essential g++
cd irrlicht-1.8.4/source/Irrlicht
make
cd ../
sudo cp -r Irrlicht /usr/local/lib
sudo cp -r Irrlicht /usr/local/include
rm irrlicht-1.8.4.zip
rm -rf irrlicht-1.8.4
sudo apt-get install libsfml-dev

## compiler
cmake -H./ -B_builds
cmake --build _builds -- -j3
