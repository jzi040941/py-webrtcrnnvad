from ._py_webrtcrnnvad import *

__version__ = "0.0.1"

class RNNVAD:
    """
    This is class of WebRTC RNNVAD
    based on https://jmvalin.ca/demo/rnnoise/
    """
    def __init__(self):
        self.st = rnnoise_create()
    
    def processFrame(self, frame):
        """
        :param frame: (np.ndarray) frame of 48k audio range is -32767.0 ~ 32768.0 
        dtype is float32, frame lenghth should be 480 
        """
        assert frame.shape==(480,)
        return rnnvad_process_npframe(self.st, frame)
    
    def reset(self):
        """ """
        rnnoise_destory(self.st)
        self.st = rnnoise_create()