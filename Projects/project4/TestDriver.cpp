using namespace std;

#include <iostream>

#include "PinHit.h"
#include "Heap.h"


int main()
{
  // Testing PinHit.h:
      // 1. default constructor, GetKey(), and GetValue()
      PinHit myP;
      cout << "myP has a Pin of " << myP.GetKey() << " and number of hits of " << myP.GetValue() << endl;
      PinHit myP2(5953,1);
      cout << "myP has a Pin of " << myP2.GetKey() << " and number of hits of " << myP2.GetValue() << endl;
      PinHit myP3 = myP2;
      cout << "myP has a Pin of " << myP3.GetKey() << " and number of hits of " << myP3.GetValue() << endl;
      if(myP2 == myP3)
        cout << "==? true" << endl;
      else
        cout << "==? false" << endl;
      myP3.IncrementHits();
      if(myP == myP3)
        cout << "==? true" << endl;
      else
        cout << "==? false" << endl;
      cout << "myP has a Pin of " << myP3.GetKey() << " and number of hits of " << myP3.GetValue() << endl;
      myP3.SetKey(5555);
      cout << "myP has a Pin of " << myP3.GetKey() << " and number of hits of " << myP3.GetValue() << endl;
      cout << myP3.GetValue() << "-" << myP3.GetValue() << "=" << myP3.CompareTo(myP3) << endl;
      cout << myP3.GetValue() << "-" << myP2.GetValue() << "=" << myP3.CompareTo(myP2) << endl;
      cout << myP2.GetValue() << "-" << myP3.GetValue() << "=" << myP2.CompareTo(myP3) << endl;
}
