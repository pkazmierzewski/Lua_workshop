#ifndef G_UNIT_TEST_H
#define G_UNIT_TEST_H

#include "gadget.h"

class gUnitTest: public eGadget
{
    DECLARE_GADGET_CLASS()

public:
    gUnitTest();

    void update(lua_State* aLua, float aDelta);

    // props
    DECLARE_GADGET_ACCESSOR(getVal, setVal)

private:
    int iVal;
};

#endif // G_UNIT_TEST_H