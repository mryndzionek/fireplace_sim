# fireplace_sim

Fireplace sound simulator in C using [Faust](https://faust.grame.fr/).
Audio output thanks to [RtAudio](https://www.music.mcgill.ca/~gary/rtaudio/).

## Building

```
mkdir deps
cd deps
git clone https://github.com/thestk/rtaudio.git -b 5.2.0
cd rtaudio
./autogen.sh
./configure --prefix=$PWD/../../local
make
make check
make install
cd ..
mkdir build
cd build
cmake ..
make
```

## Running

```
./fireplace [optional samplerate (default: 44100)]
```

You should hear something like:
[fireplace.mp3](data/fireplace.mp3)
