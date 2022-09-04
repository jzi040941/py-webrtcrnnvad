# py-webrtcrnnvad
Python interface to the RNNoise VAD(Voice Activity Detection) component inside webrtc

[![Gitter][gitter-badge]][gitter-link]

|      CI              | status |
|----------------------|--------|
| pip builds           | [![Pip Actions Status][actions-pip-badge]][actions-pip-link] |
| [`cibuildwheel`][]   | [![Wheels Actions Status][actions-wheels-badge]][actions-wheels-link] |

[gitter-badge]:            https://badges.gitter.im/pybind/Lobby.svg
[gitter-link]:             https://gitter.im/pybind/Lobby
[actions-pip-link]:        https://github.com/jzi040941/py-webrtcrnnvad/actions/workflows/pip.yml
[actions-pip-badge]:       https://github.com/jzi040941/py-webrtcrnnvad/actions/workflows/pip.yml/badge.svg
[actions-wheels-link]:     https://github.com/jzi040941/py-webrtcrnnvad/actions/workflows/wheels.yml
[actions-wheels-badge]:    https://github.com/jzi040941/py-webrtcrnnvad/actions/workflows/wheels.yml/badge.svg 

## Prerequisites

* A compiler with C++11 support
* Pip 10+ or CMake >= 3.4 (or 3.8+ on Windows, which was the first version to support VS 2015)
* Ninja or Pip 10+
* Numpy


## Installation

```
pip install py_webrtcrnnvad
```

## License
RNNoise - BSD
PyBind - BSD


## Test call

```python
import py_webrtcrnnvad
audio, fs = read_wave("audio.wav")
frames = frame_generator(10, audio, 48000)
frame = np.frombuffer(frames[0].bytes, dtype=np.short)
vad = py_webrtcrnnvad.RNNVAD()
vad.processFrame(frame.astype(np.float32))
```

[`cibuildwheel`]:          https://cibuildwheel.readthedocs.io
[FAQ]: http://pybind11.rtfd.io/en/latest/faq.html#working-with-ancient-visual-studio-2009-builds-on-windows
[vs2015_runtime]: https://www.microsoft.com/en-us/download/details.aspx?id=48145
[scikit-build]: https://scikit-build.readthedocs.io/en/latest/
