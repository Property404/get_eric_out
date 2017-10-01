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

def pitchTo(value):
	_ser.write(_make_command("pt", value));

def pitchUp(value):
	_ser.write(_make_command("pu", value));
def pitchDown(value):
	_ser.write(_make_command("pd", value));
