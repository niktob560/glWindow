# glWindow
Library for creating OpenGL-based windows using xml markup(yup, as in Android)  
This library is writting __only JFF__, don't use it in production


### BaseGlObjects messaging system:
Usage:
```C++
BaseGlObject.sendMessage(type_of_message, map_with_data_for_message);
```
Example:
```C++
BaseGlObject o();
o.sendMessage(BaseGlObj::TYPE_ETC, 
  {
      std::make_pair(BaseGlObj::MSG_PART_X, 100), 
      std::make_pair(BaseGlObj::MSG_PART_Y, 100)
  });
```
That's important to use only std::map<int, int>
