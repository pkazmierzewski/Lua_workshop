Class = "Base"
Super = _G.eLuaModuleMgr.derive("scripts/Actor.lua")

function Init(me)
    if (me.base ~= nil) then
	_G.assert(false)
    end
    me.base = 1
end