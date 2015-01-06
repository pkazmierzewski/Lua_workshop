Class = "Background"
Derives = "scripts/Actor.lua"

function OnInit(me)
    me.gTexture = _G.gTexture.create(me)
    me.gTexture:setName("textures/background.png")
    me.gTexture:setSdlRectW(800)
    me.gTexture:setSdlRectH(600)
    me.gTexture:enable()
    shift(me, state_main)
end

state_main = {
    enter = function(me)
    end,

    leave = function(me)
    end,

    update = function(me)
    end
}