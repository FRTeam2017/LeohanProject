#!/bin/sh
# Install Python prerequisites on NVIDIA Jetson TK1 for iTorch or ubuntu 16.04
# This is for https://github.com/facebook/iTorch
# L4T 21.3, Torch 7 (http://torch.ch)
# Python 2.7 or greater must be installed before running this script
# Torch 7 should already be installed before running this script
# iPython is loaded using pip, as repository version is 1.x version, > 2.0 is needed
# Need to compile from source as repository version libzmq3-dev is not the correct revision
wget http://download.zeromq.org/zeromq-4.0.5.tar.gz
tar xzvf zeromq-4.0.5.tar.gz
cd zeromq-4.0.5
./configure
make
sudo make install
cd ..

sudo apt-get install python-dev -y
sudo apt-get install python-pip -y
sudo pip install ipython
sudo apt-get install python-zmq -y
sudo apt-get install python-markupsafe -y
sudo apt-get install python-jsonschema -y
sudo pip install jinja2
sudo pip install tornado
sudo luarocks install luacrypto 
sudo luarocks install env
sudo luarocks install lzmq
sudo luarocks install lbase64
sudo luarocks install uuid
# add some decoders for iTorch audio and video
sudo apt-get install gstreamer1.0-libav -y
# Install iTorch
git clone https://github.com/facebook/iTorch.git
cd iTorch
sudo env "PATH=$PATH" luarocks make
sudo chown -R $USER $(dirname $(ipython locate profile))
