import serial

_ser = serial.Serial("/dev/cu.usbmodemFA141")
_bytes = 2

def _make_command(string, value):
	return string + chr(value>>8) + chr(value - ((value>>8)<<8))

def yawnTo(value):
	_ser.write(_make_command("yt", value));

def yawnRight(value):
	_ser.write(_make_command("yr", value));
def yawnLeft(value):
	_ser.write(_make_command("yl", value));

