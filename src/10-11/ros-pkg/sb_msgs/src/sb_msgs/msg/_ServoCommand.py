"""autogenerated by genmsg_py from ServoCommand.msg. Do not edit."""
import roslib.message
import struct


class ServoCommand(roslib.message.Message):
  _md5sum = "0638299d4e64a023ad0af9c6a2fd2ef2"
  _type = "sb_msgs/ServoCommand"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# A servo command that the furiousDriver.py node can understand.

int32 id  # The integer id of the servo
int32 pwm # The raw servo value

int32 throttle
int32 steering
int32 pan
int32 tilt

bool usingServo

"""
  __slots__ = ['id','pwm','throttle','steering','pan','tilt','usingServo']
  _slot_types = ['int32','int32','int32','int32','int32','int32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       id,pwm,throttle,steering,pan,tilt,usingServo
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(ServoCommand, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = 0
      if self.pwm is None:
        self.pwm = 0
      if self.throttle is None:
        self.throttle = 0
      if self.steering is None:
        self.steering = 0
      if self.pan is None:
        self.pan = 0
      if self.tilt is None:
        self.tilt = 0
      if self.usingServo is None:
        self.usingServo = False
    else:
      self.id = 0
      self.pwm = 0
      self.throttle = 0
      self.steering = 0
      self.pan = 0
      self.tilt = 0
      self.usingServo = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_6iB.pack(_x.id, _x.pwm, _x.throttle, _x.steering, _x.pan, _x.tilt, _x.usingServo))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      _x = self
      start = end
      end += 25
      (_x.id, _x.pwm, _x.throttle, _x.steering, _x.pan, _x.tilt, _x.usingServo,) = _struct_6iB.unpack(str[start:end])
      self.usingServo = bool(self.usingServo)
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_6iB.pack(_x.id, _x.pwm, _x.throttle, _x.steering, _x.pan, _x.tilt, _x.usingServo))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 25
      (_x.id, _x.pwm, _x.throttle, _x.steering, _x.pan, _x.tilt, _x.usingServo,) = _struct_6iB.unpack(str[start:end])
      self.usingServo = bool(self.usingServo)
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_6iB = struct.Struct("<6iB")
