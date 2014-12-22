#ifndef ACTOR_H
#define ACTOR_H

#include "fsm.h"
#include "userdata.h"

#include <list>
#include <string>
#include <vector>

class eGadget;
class eLuaState;
struct sModule;

struct sActorSharedInternal
{
    sActorSharedInternal(const char* aName, void* aAddress):
	iName(aName),
	iAddress(aAddress) {}

    const char* iName;
    void* iAddress;
};

class eActor
{
    DECLARE_USERDATA_CLASS()

public:
    eActor(const std::string& aScript);
    ~eActor();

    void doScript(lua_State* aLua);
    void update(lua_State* aLua);
    void callOnInit(lua_State* aLua);
    void callOnRestart(lua_State* aLua);
    void callLuaFunc(lua_State* aLua, const char* aFunctionName);
    const std::string& getScript() const { return iScript; }
    std::vector<eGadget*>::size_type getGadgetsNum() const { return iGadgets.size(); }
    void shift(lua_State* aLua) { iFsm.shift(aLua); }
    int getMeRef() const { return iMeRef.front(); }

private:
    eActor(const eActor& aOther);
    eActor& operator=(const eActor& aOther);

    void createMeTables(lua_State* aLua);
    void callLuaFuncWithEnv(lua_State* aLua, int aModuleRef, int aMeRef, const char* aFunctionName);
    void callLuaFuncThroughInheritanceHierarchyBackward(lua_State* aLua, const char* aFunctionName);
    void shareInternalsWithScript(lua_State* aLua, int aRef);
    void createGadgetsContainer(lua_State* aLua);

private:
    eFsm iFsm;
    std::list<int> iMeRef;
    std::string iScript;
    const sModule* iModule;
    std::vector<eGadget*> iGadgets;
};

#endif // ACTOR_H
