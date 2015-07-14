



#include <GinSing.h>

GinSing  GS; 


#define rcvPin  4       // this is the pin used for receiving    ( can be either 4 or 12 )
#define sndPin  3       // this is the pin used for transmitting ( can be either 3 or 11 ) 
#define ovfPin  2       // this is the pin used for overflow control ( can be either 2 or 10 )


void setup() {
  // put your setup code here, to run once:
  GS.begin( rcvPin , sndPin , ovfPin );
  
  speakIntro();
  GS.end();
}
void shutdown()
{
   
  // Although technically you may not need to shut down the interface, it is advised when you want to stop working with it;
  // otherwise you may find sounds will continue to play even though you're done with your code.

  GS.end();

}

void speakIntro()
{
  GinSingVoice *v = GS.getVoice();                                  // get the voice mode class interface
  
   v->begin();                                                      // enter voice mode
   v->setNote ( D_2 );                                              // set voice pitch
   GSAllophone  hello[] = { _HE , _PITCHUP , _E , _LO ,_PITCHDN ,  _OE , _PA1 , _ENDPHRASE }; 
   GSAllophone welcome[] = {_IE , _A , _M ,                         // define what will be spoken
                             _BENDDN , _J, _I , _NE , _SE ,         // this phrase is I am GinSing
                            _PITCHDN , _I , _PITCHDN , _NGE ,       // with pitch and bend
                            _PA0 , _ENDPHRASE };                    // use _ENDPHRASE to end phrase
                            
    GSAllophone  ciaran[] = { _KE , _PITCHUP , _EE , _R ,_PITCHDN ,  _AA ,_NO , _PA1 , _ENDPHRASE }; 
    GSAllophone  want[] = { _DO , _PITCHUP, _OO ,_PA2, _Y ,_PITCHDN ,  _OO ,_OO , _PA1 ,_W,_AA, _PITCHUP, _NO,_T, _PA2, _ENDPHRASE }; 
    GSAllophone  cup[] = { _A,_PA2,_KO , _U ,_PA2, _PO  , _ENDPHRASE };   
    GSAllophone  tea[] = { _AA,_V, _PITCHDN, _T,_EE,_PITCHDN , _ENDPHRASE }; 
    v->speak ( hello );  
        // speak the phrase
    v->speak ( ciaran );
    v->setNote ( E_2);
    v->speak ( want );
    v->setNote ( D_2);
    v->speak ( cup );
    v->setNote ( E_2);
    v->speak ( tea );
    delay ( v->getMillis ( want ) + 500 );                       // wait for speaking to finish
}


void loop(){
  
  
}


