Class = "A"
Super = _G.eLuaModuleMgr.derive("scripts/Actor.lua")

function fun1(me)
    me.val = "actor A"
end

function fun(me)
    me.Env.fun1(me)
end
