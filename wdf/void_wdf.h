

class BaseWDF {
public:
  float a;
  float b;
  float R;
}

//-----------------------------------------------------------

template<typename T> 
class Resistor : BaseWDF {


}


//-----------------------------------------------------------

template<typename Port1type, typename Port2type>
class SeriesAdaptor : BaseWDF {

public SeriesAdaptor(Port1type Port1, Port2type Port2) {

}

//-----------------------------------------------------------
