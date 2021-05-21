-- How to define game objects in the scene file
-- Step1: HowManyGameObjects must contain one more number than the last go_X that was declared because these start at 0
-- 		  If you want to add a go add one to this variable
-- Step2: Structure
--  go_Number = {}   								-> where "Number" is the next to the last go declared
--  go_Number[0] = { Name = "", HowManyCmps = X}	-> Name is the name of the GameObject. HowManyCmps is the number of components of the go
--  go_Number[1] = { Component = " ", General Data} -> Component is the ENUM used to identify the COMPONENT (getComponentType method from LuaParser). 
--													   General Data is the component data

-- You must bear in mind that in the definition of go, the first position of the array will always be the data that it needs to know its name 
-- and how many components it has. The following positions in the array will be used to define the components

-- You can find component definition examples at the end of this document

HowManyGameObjects = 126
-- Player
go_0 = {}
go_0[0] = { Name = "Player", HowManyCmps = 13, Persist = false}
go_0[1] = { Component = "Transform",  Coord = {X = 0, Y = 1.75, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=1, Y = 2, Z = 1}}
go_0[2] = { Component = "Camera", Plane = {Near = 0.1, Far = 100}, Compositors = {"JugadorVisionWeak", false, "JugadorVisionStrong", false, "JugadorVisionInjured", false}, SlaveRotation=false}
go_0[3] = { Component = "Listener", ListenerNumber = 0, Velocity = {X = 0, Y = 0, Z = 0} }
go_0[4] = { Component = "PlayerInteractiveComponent" }
go_0[5] = { Component = "PlayerKeysComponent"}
go_0[6] = { Component = "HealthComponent", HP=2 }
go_0[7] = { Component = "PlayerVisibilityComponent" }
go_0[8] = { Component = "RigidBody", Type="Box", Mass=10, Width=0.25,Height=1,Depth=0.25, Kinematic = false, ConstrainAngle = true, IsTrigger=false}
go_0[9] = { Component = "PlayerMovementComponent", SpeedForward = 320, SpeedSideWays = 260, SpeedBackwards = 260, CameraSpeed = 15}
go_0[10] = { Component = "PlayerLookEnemyGlitchComponent"}
go_0[11] = { Component = "UIManagerComponent"}
go_0[12] = { Component = "AudioSource", Route = {"Assets/Audio/FootStep2.wav", "Assets/Audio/Footsteps1.ogg"}}
go_0[13] = { Component = "LightComponent", LightType= "POINT", Visible = true, 
											Attenuation = {Range = 200, Constant = 1.0, Linear = 0.30, Quadratic=2},
											Diffuse = {Red = 1, Green= 1, Blue = 1}, 
											Specular = {Red = 1, Green= 1, Blue = 1},
											LightDirection = {X = 0, Y = 0, Z = 0},
											Intensity=5}


-- Suelo
go_1 = {}
go_1[0] = { Name = "Suelo", HowManyCmps = 3, Persist = false}
go_1[1] = { Component = "Transform", Coord = {X = 0, Y = -0.5, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 200, Y = 1, Z = 150}}
go_1[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_1[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

-- FirstAidKit
go_2 = {}
go_2[0] = { Name = "FirstAidKit", HowManyCmps = 4, Persist = false}
go_2[1] = { Component = "Transform", Coord = {X = -23.25, Y = 0, Z = 8.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .8, Y = .2, Z = .8}}
go_2[2] = { Component = "RenderObject", MeshName="firstAid.mesh", Material="botiquin", Visible=true, Shadows=false, RenderingDistance = 50}
go_2[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=10,Depth=1,IsTrigger=true}
go_2[4] = { Component = "FirstAidKitComponent", HealthAmount = 10 }


go_3 = {}
go_3[0] = { Name = "Key", HowManyCmps = 5, Persist = false}
go_3[1] = { Component = "Transform", Coord = {X = 30, Y = 0.4, Z = 8.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 0.8, Y = 0.8, Z = 0.8}}
go_3[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Brown", Visible=true, Shadows=false, RenderingDistance = 50}
go_3[3] = { Component = "SphereCollider",Radius=1,IsTrigger=true}
go_3[4] = { Component = "KeyComponent" }
go_3[5] = { Component = "AudioSource", Route = {"Assets/Audio/KeyPickUp.wav" }, StopOnDestroy = false}

go_4 = {}
go_4[0] = { Name = "Puerta", HowManyCmps = 5, Persist = false}
go_4[1] = { Component = "Transform", Coord = {X = -35.5, Y = 0, Z = 17.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 13, Y = 4, Z = 1}}
go_4[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Orange", 
						RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
						Visible=true, Shadows=false, RenderingDistance = 1000}
go_4[3] = { Component = "SphereCollider",Radius=10,IsTrigger=true}
go_4[4] = { Component = "BoxCollider", Type="Box",Width=1,Height=1,Depth=1,IsTrigger=false}
go_4[5] = { Component = "DoorComponent" }

-- UI Manager
go_5 = {}
go_5[0] = { Name = "UIManager", HowManyCmps = 2, Persist = false}
go_5[1] = { Component = "Transform"}
go_5[2] = { Component = "OverlayComponent", Name = "GameUI", Hide = false}
-- Bush parte 1
go_6 = {}
go_6[0] = { Name = "Bush1", HowManyCmps = 4, Persist = false}
go_6[1] = { Component = "Transform", Coord = {X = -29.1, Y = 1, Z = -6.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.75, Y = 2, Z = 1.5}}
go_6[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", Visible=true, Shadows=false, RenderingDistance = 50}
go_6[3] = { Component = "SphereCollider", Radius=1,IsTrigger=true}
go_6[4] = { Component = "HideoutComponent" }
-- Trampa
go_7 = {}
go_7[0] = { Name = "Trampa1", HowManyCmps = 5, Persist = false}
go_7[1] = { Component = "Transform", Coord = {X = -16.8, Y = 0.1, Z = -10.8}, Rotation = {X = -90, Y = 90, Z = 0}, Scale = {X = 2, Y = 2, Z = 4}}
go_7[2] = {	Component = "RenderObject", MeshName="spikes.mesh", Material="pincho", Visible=true, Shadows=true, RenderingDistance = 50}
go_7[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=1,Depth=50,IsTrigger=true}
go_7[4] = { Component = "TrapComponent",EnabledMaterial="Practica1/Red"}
go_7[5] = { Component = "AudioSource", Route = {"Assets/Audio/MetalHit.wav" }, StopOnDestroy = false}

-- Desactivador
go_8 = {}
go_8[0] = { Name = "Desactivador1", HowManyCmps = 5, Persist = false}
go_8[1] = { Component = "Transform", Coord = {X = -16.75, Y = 0.2, Z = -12.2}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .3, Y = .4, Z = .3}}
go_8[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Metal", Visible=true, Shadows=true, RenderingDistance = 50}
go_8[3] = { Component = "SphereCollider",Radius=2,IsTrigger=true}
go_8[4] = { Component = "ObjectDeactivatorComponent",ObjName="Trampa1"}
go_8[5] = { Component = "AudioSource", Route = {"Assets/Audio/SwitchSound.mp3" }, StopOnDestroy = false}


-- Paredes
--  SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN  
go_9 = {}
go_9[0] = { Name = "ParedS1", HowManyCmps = 3, Persist = false}
go_9[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=5, Y = 4, Z = 5}}
go_9[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_9[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_10 = {}
go_10[0] = { Name = "ParedS2", HowManyCmps = 3, Persist = false}
go_10[1] = { Component = "Transform", Coord = {X = 5.75, Y = 2, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7.5, Y = 4, Z = 6}}
go_10[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_10[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_11 = {}
go_11[0] = { Name = "ParedS3", HowManyCmps = 3, Persist = false}
go_11[1] = { Component = "Transform", Coord = {X = 0, Y = 2, Z = 4.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 4}}
go_11[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_11[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_12 = {}
go_12[0] = { Name = "ParedS4", HowManyCmps = 3, Persist = false}
go_12[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_12[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_12[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

-- ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A

go_13 = {}
go_13[0] = { Name = "ParedA1", HowManyCmps = 3, Persist = false}
go_13[1] = { Component = "Transform", Coord = {X = -1.5, Y = 2, Z = -5.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=9, Y = 4, Z = 1}}
go_13[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_13[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_14 = {}
go_14[0] = { Name = "ParedA2", HowManyCmps = 3, Persist = false}
go_14[1] = { Component = "Transform", Coord = {X = 6.25, Y = 2, Z = -6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 3}}
go_14[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_14[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_15 = {}
go_15[0] = { Name = "ParedA3", HowManyCmps = 3, Persist = false}
go_15[1] = { Component = "Transform", Coord = {X = 1, Y = 2, Z = -7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 0.75}}
go_15[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_15[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_16 = {}
go_16[0] = { Name = "ParedA4", HowManyCmps = 3, Persist = false}
go_16[1] = { Component = "Transform", Coord = {X = -4.25, Y = 2, Z = -7}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3.5, Y = 4, Z = 2}}
go_16[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_16[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_17 = {}
go_17[0] = { Name = "ParedA5", HowManyCmps = 3, Persist = false}
go_17[1] = { Component = "Transform", Coord = {X = -4.25, Y = 2, Z = -10.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3.5, Y = 4, Z = 2}}
go_17[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_17[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_18 = {}
go_18[0] = { Name = "ParedA6", HowManyCmps = 3, Persist = false}
go_18[1] = { Component = "Transform", Coord = {X = -0.5, Y = 2, Z = -11.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=11, Y = 4, Z = 1}}
go_18[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_18[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_19 = {}
go_19[0] = { Name = "ParedA7", HowManyCmps = 3, Persist = false}
go_19[1] = { Component = "Transform", Coord = {X = 0.5, Y = 2, Z = -8.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 2}}
go_19[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_19[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_20 = {}
go_20[0] = { Name = "ParedA8", HowManyCmps = 3, Persist = false}
go_20[1] = { Component = "Transform", Coord = {X = 4.5, Y = 2, Z = -10.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_20[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_20[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


--- ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B

go_21 = {}
go_21[0] = { Name = "ParedB1", HowManyCmps = 3, Persist = false}
go_21[1] = { Component = "Transform", Coord = {X = 11.75, Y = 2, Z = -10.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4.5, Y = 4, Z = 3}}
go_21[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_21[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_22 = {}
go_22[0] = { Name = "ParedB2", HowManyCmps = 3, Persist = false}
go_22[1] = { Component = "Transform", Coord = {X = 18.625, Y = 2, Z = -10.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=5.75, Y = 4, Z = 3}}
go_22[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_22[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_23 = {}
go_23[0] = { Name = "ParedB3", HowManyCmps = 3, Persist = false}
go_23[1] = { Component = "Transform", Coord = {X = 12.75, Y = 2, Z = -6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6.5, Y = 4, Z = 2.8}}
go_23[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_23[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_24 = {}
go_24[0] = { Name = "ParedB4", HowManyCmps = 3, Persist = false}
go_24[1] = { Component = "Transform", Coord = {X = 19.5, Y = 2, Z = -7.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 4.5}}
go_24[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_24[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


--  ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C  

go_25 = {}
go_25[0] = { Name = "ParedC1", HowManyCmps = 3, Persist = false}
go_25[1] = { Component = "Transform", Coord = {X = 12.5, Y = 2, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 6}}
go_25[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_25[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_26 = {}
go_26[0] = { Name = "ParedC2", HowManyCmps = 3, Persist = false}
go_26[1] = { Component = "Transform", Coord = {X = 10.5, Y = 2, Z = 6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6, Y = 4, Z = 3}}
go_26[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_26[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_27 = {}
go_27[0] = { Name = "ParedC3", HowManyCmps = 3, Persist = false}
go_27[1] = { Component = "Transform", Coord = {X = 17.5, Y = 2, Z = -0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 4}}
go_27[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_27[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_28 = {}
go_28[0] = { Name = "ParedC4", HowManyCmps = 3, Persist = false}
go_28[1] = { Component = "Transform", Coord = {X = 17.5, Y = 2, Z = 7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 4}}
go_28[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_28[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_29 = {}
go_29[0] = { Name = "ParedC5", HowManyCmps = 3, Persist = false}
go_29[1] = { Component = "Transform", Coord = {X = 19, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 4}}
go_29[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_29[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_30 = {}
go_30[0] = { Name = "ParedC6", HowManyCmps = 3, Persist = false}
go_30[1] = { Component = "Transform", Coord = {X = 15.5, Y = 2, Z = 2}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 1}}
go_30[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_30[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_31 = {}
go_31[0] = { Name = "ParedC7", HowManyCmps = 3, Persist = false}
go_31[1] = { Component = "Transform", Coord = {X = 15.5, Y = 2, Z = 5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 1}}
go_31[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_31[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


--  ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D  

go_32 = {}
go_32[0] = { Name = "ParedD1", HowManyCmps = 3, Persist = false}
go_32[1] = { Component = "Transform", Coord = {X = 24.5, Y = 2, Z = -1.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_32[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_32[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_33 = {}
go_33[0] = { Name = "ParedD2", HowManyCmps = 3, Persist = false}
go_33[1] = { Component = "Transform", Coord = {X = 25.5, Y = 2, Z = -3.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 2.5}}
go_33[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_33[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_34 = {}
go_34[0] = { Name = "ParedD3", HowManyCmps = 3, Persist = false}
go_34[1] = { Component = "Transform", Coord = {X = 23.25, Y = 2, Z = 6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 6}}
go_34[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_34[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_35 = {}
go_35[0] = { Name = "ParedD4", HowManyCmps = 3, Persist = false}
go_35[1] = { Component = "Transform", Coord = {X = 24.75, Y = 2, Z = 2.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_35[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_35[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

--  ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E  
go_36 = {}
go_36[0] = { Name = "ParedE1", HowManyCmps = 3, Persist = false}
go_36[1] = { Component = "Transform", Coord = {X = -14.5, Y = 2, Z = -1.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2.5}}
go_36[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_36[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_37 = {}
go_37[0] = { Name = "ParedE2", HowManyCmps = 3, Persist = false}
go_37[1] = { Component = "Transform", Coord = {X = -12.5, Y = 2, Z = -3}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 1.5}}
go_37[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_37[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_38 = {}
go_38[0] = { Name = "ParedE3", HowManyCmps = 3, Persist = false}
go_38[1] = { Component = "Transform", Coord = {X = -18, Y = 2, Z = -8}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 5.5}}
go_38[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_38[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_39 = {}
go_39[0] = { Name = "ParedE4", HowManyCmps = 3, Persist = false}
go_39[1] = { Component = "Transform", Coord = {X = -11.75, Y = 2, Z = -7}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3.5, Y = 4, Z = 7.5}}
go_39[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_39[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_40 = {}
go_40[0] = { Name = "ParedE5", HowManyCmps = 3, Persist = false}
go_40[1] = { Component = "Transform", Coord = {X = -20.5, Y = 2, Z = -4}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 3}}
go_40[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_40[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_41 = {}
go_41[0] = { Name = "ParedE6", HowManyCmps = 3, Persist = false}
go_41[1] = { Component = "Transform", Coord = {X = -18.75, Y = 2, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 5}}
go_41[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_41[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_42 = {}
go_42[0] = { Name = "ParedE7", HowManyCmps = 3, Persist = false}
go_42[1] = { Component = "Transform", Coord = {X = -17.55, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3.75, Y = 4, Z = 2}}
go_42[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_42[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_43 = {}
go_43[0] = { Name = "ParedE8", HowManyCmps = 3, Persist = false}
go_43[1] = { Component = "Transform", Coord = {X = -26, Y = 2, Z = 2.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 13, Y = 4, Z = 4.5}}
go_43[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_43[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

--  ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F    ZONA F  
go_44 = {}
go_44[0] = { Name = "ParedF1", HowManyCmps = 3, Persist = false}
go_44[1] = { Component = "Transform", Coord = {X = -12, Y = 2, Z = 4}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3, Y = 4, Z = 3.5}}
go_44[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_44[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_45 = {}
go_45[0] = { Name = "ParedF2", HowManyCmps = 3, Persist = false}
go_45[1] = { Component = "Transform", Coord = {X = -9.75, Y = 2, Z = 3}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 5.5}}
go_45[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_45[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_46 = {}
go_46[0] = { Name = "ParedF3", HowManyCmps = 3, Persist = false}
go_46[1] = { Component = "Transform", Coord = {X = -8.5, Y = 2, Z = 5.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 1}}
go_46[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_46[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

-- ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G 

go_47 = {}
go_47[0] = { Name = "ParedG1", HowManyCmps = 3, Persist = false}
go_47[1] = { Component = "Transform", Coord = {X = -11, Y = 2, Z = 9}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7, Y = 4, Z = 2}}
go_47[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_47[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_48 = {}
go_48[0] = { Name = "ParedG2", HowManyCmps = 3, Persist = false}
go_48[1] = { Component = "Transform", Coord = {X = -13.5, Y = 2, Z = 14.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 10}}
go_48[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_48[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_49 = {}
go_49[0] = { Name = "ParedG3", HowManyCmps = 3, Persist = false}
go_49[1] = { Component = "Transform", Coord = {X = -10, Y = 2, Z = 19.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6, Y = 4, Z = 4}}
go_49[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_49[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_50 = {}
go_50[0] = { Name = "ParedG4", HowManyCmps = 3, Persist = false}
go_50[1] = { Component = "Transform", Coord = {X = -11.5, Y = 2, Z = 16.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_50[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_50[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_51 = {}
go_51[0] = { Name = "ParedG5", HowManyCmps = 3, Persist = false}
go_51[1] = { Component = "Transform", Coord = {X = -8, Y = 2, Z = 16.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_51[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_51[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_52 = {}
go_52[0] = { Name = "ParedG6", HowManyCmps = 3, Persist = false}
go_52[1] = { Component = "Transform", Coord = {X = -7.5, Y = 2, Z = 10}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 4}}
go_52[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_52[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_53 = {}
go_53[0] = { Name = "ParedG7", HowManyCmps = 3, Persist = false}
go_53[1] = { Component = "Transform", Coord = {X = -9, Y = 2, Z = 12.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4.5, Y = 4, Z = 2}}
go_53[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_53[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


--  LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1    LIMITES PARTE 1  

go_54 = {}
go_54[0] = { Name = "ParedLimite1", HowManyCmps = 3, Persist = false}
go_54[1] = { Component = "Transform", Coord = {X = 10.5, Y = 2, Z = -19}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 34, Y = 4, Z = 10}}
go_54[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_54[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_55 = {}
go_55[0] = { Name = "ParedLimite2", HowManyCmps = 3, Persist = false}
go_55[1] = { Component = "Transform", Coord = {X = 28.5, Y = 2, Z = -10.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 7}}
go_55[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_55[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_56 = {}
go_56[0] = { Name = "ParedLimite3", HowManyCmps = 3, Persist = false}
go_56[1] = { Component = "Transform", Coord = {X = 31.5, Y = 2, Z = -2}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 11}}
go_56[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_56[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_57 = {}
go_57[0] = { Name = "ParedLimite4", HowManyCmps = 3, Persist = false}
go_57[1] = { Component = "Transform", Coord = {X = 33, Y = 2, Z = 7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 8}}
go_57[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_57[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_58 = {}
go_58[0] = { Name = "ParedLimite5", HowManyCmps = 3, Persist = false}
go_58[1] = { Component = "Transform", Coord = {X = -7.5, Y = 2, Z = -20}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_58[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_58[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_59 = {}
go_59[0] = { Name = "ParedLimite6", HowManyCmps = 3, Persist = false}
go_59[1] = { Component = "Transform", Coord = {X = -16.75, Y = 2, Z = -17.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 16.5, Y = 4, Z = 10}}
go_59[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_59[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_60 = {}
go_60[0] = { Name = "ParedLimite7", HowManyCmps = 3, Persist = false}
go_60[1] = { Component = "Transform", Coord = {X = -27.5, Y = 2, Z = -10.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 5.5}}
go_60[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_60[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_61 = {}
go_61[0] = { Name = "ParedLimite8", HowManyCmps = 3, Persist = false}
go_61[1] = { Component = "Transform", Coord = {X = -35, Y = 2, Z = -5.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 6}}
go_61[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_61[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_62 = {}
go_62[0] = { Name = "ParedLimite9", HowManyCmps = 3, Persist = false}
go_62[1] = { Component = "Transform", Coord = {X = -39, Y = 2, Z = -1.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_62[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_62[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_63 = {}
go_63[0] = { Name = "ParedLimite10", HowManyCmps = 3, Persist = false}
go_63[1] = { Component = "Transform", Coord = {X = -37, Y = 2, Z = 2.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 6.5}}
go_63[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_63[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_64 = {}
go_64[0] = { Name = "ParedLimite11", HowManyCmps = 3, Persist = false}
go_64[1] = { Component = "Transform", Coord = {X = -31, Y = 2, Z = 7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7, Y = 4, Z = 4}}
go_64[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_64[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


-- ZONA DERECHA G ZONA DERECHA G ZONA DERECHA G ZONA DERECHA GZONA DERECHA G ZONA DERECHA G ZONA DERECHA G ZONA DERECHA G ZONA DERECHA G  ZONA DERECHA G

go_65 = {}
go_65[0] = { Name = "ParedDERECHAG1", HowManyCmps = 3, Persist = false}
go_65[1] = { Component = "Transform", Coord = {X = -2.5, Y = 2, Z = 10.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 5}}
go_65[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_65[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_66 = {}
go_66[0] = { Name = "ParedDERECHAG2", HowManyCmps = 3, Persist = false}
go_66[1] = { Component = "Transform", Coord = {X = -4.5, Y = 2, Z = 18.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 6}}
go_66[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_66[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


go_67 = {}
go_67[0] = { Name = "ParedDERECHAG3", HowManyCmps = 3, Persist = false}
go_67[1] = { Component = "Transform", Coord = {X = -1, Y = 2, Z = 19}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2.5, Y = 4, Z = 5}}
go_67[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_67[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_68 = {}
go_68[0] = { Name = "ParedDERECHAG4", HowManyCmps = 3, Persist = false}
go_68[1] = { Component = "Transform", Coord = {X = -3, Y = 2, Z = 21}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 1}}
go_68[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_68[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


go_69 = {}
go_69[0] = { Name = "ParedDERECHAG5", HowManyCmps = 3, Persist = false}
go_69[1] = { Component = "Transform", Coord = {X = -1.25, Y = 2, Z = 13.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2.5, Y = 4, Z = 2}}
go_69[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_69[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

-- ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J ZONA J 

go_70 = {}
go_70[0] = { Name = "ParedJ1", HowManyCmps = 3, Persist = false}
go_70[1] = { Component = "Transform", Coord = {X = 3.25, Y = 2, Z = 19}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2.5, Y = 4, Z = 5}}
go_70[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_70[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_71 = {}
go_71[0] = { Name = "ParedJ2", HowManyCmps = 3, Persist = false}
go_71[1] = { Component = "Transform", Coord = {X = 5, Y = 2, Z = 20}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4, Y = 4, Z = 3}}
go_71[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_71[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_72 = {}
go_72[0] = { Name = "ParedJ3", HowManyCmps = 3, Persist = false}
go_72[1] = { Component = "Transform", Coord = {X = 3, Y = 2, Z = 11}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 6}}
go_72[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_72[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_73 = {}
go_73[0] = { Name = "ParedJ4", HowManyCmps = 3, Persist = false}
go_73[1] = { Component = "Transform", Coord = {X = 6.5, Y = 2, Z = 12.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7, Y = 4, Z = 2.5}}
go_73[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_73[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_74 = {}
go_74[0] = { Name = "ParedJ5", HowManyCmps = 3, Persist = false}
go_74[1] = { Component = "Transform", Coord = {X = 8, Y = 2, Z = 15}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4, Y = 4, Z = 2}}
go_74[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_74[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_75 = {}
go_75[0] = { Name = "ParedJ6", HowManyCmps = 3, Persist = false}
go_75[1] = { Component = "Transform", Coord = {X = 11, Y = 2, Z = 12}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 1}}
go_75[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_75[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_76 = {}
go_76[0] = { Name = "ParedJ7", HowManyCmps = 3, Persist = false}
go_76[1] = { Component = "Transform", Coord = {X = 18, Y = 2, Z = 12.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 13, Y = 4, Z = 2}}
go_76[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_76[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_77 = {}
go_77[0] = { Name = "ParedJ8", HowManyCmps = 3, Persist = false}
go_77[1] = { Component = "Transform", Coord = {X = 23.75, Y = 2, Z = 15}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 4}}
go_77[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_77[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_78 = {}
go_78[0] = { Name = "ParedJ9", HowManyCmps = 3, Persist = false}
go_78[1] = { Component = "Transform", Coord = {X = 19.75, Y = 2, Z = 16}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3, Y = 4, Z = 2}}
go_78[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_78[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_79 = {}
go_79[0] = { Name = "ParedJ10", HowManyCmps = 3, Persist = false}
go_79[1] = { Component = "Transform", Coord = {X = 19, Y = 2, Z = 20.625}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4.5, Y = 4, Z = 3}}
go_79[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_79[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_80 = {}
go_80[0] = { Name = "ParedJ11", HowManyCmps = 3, Persist = false}
go_80[1] = { Component = "Transform", Coord = {X = 14.25, Y = 2, Z = 18.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5.5, Y = 4, Z = 7}}
go_80[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_80[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_81 = {}
go_81[0] = { Name = "ParedJ12", HowManyCmps = 3, Persist = false}
go_81[1] = { Component = "Transform", Coord = {X = 10, Y = 2, Z = 19.875}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3, Y = 4, Z = 4}}
go_81[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_81[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

--  ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H    ZONA H  

go_82 = {}
go_82[0] = { Name = "ParedH1", HowManyCmps = 3, Persist = false}
go_82[1] = { Component = "Transform", Coord = {X = -20, Y = 2, Z = 7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 8, Y = 4, Z = 1}}
go_82[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_82[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_83 = {}
go_83[0] = { Name = "ParedH2", HowManyCmps = 3, Persist = false}
go_83[1] = { Component = "Transform", Coord = {X = -19.25, Y = 2, Z = 8.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6.5, Y = 4, Z = 1.5}}
go_83[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_83[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_84 = {}
go_84[0] = { Name = "ParedH3", HowManyCmps = 3, Persist = false}
go_84[1] = { Component = "Transform", Coord = {X = -17.15, Y = 2, Z = 10.65}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =2.25, Y = 4, Z = 2.25}}
go_84[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_84[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_85 = {}
go_85[0] = { Name = "ParedH4", HowManyCmps = 3, Persist = false}
go_85[1] = { Component = "Transform", Coord = {X = -16.55, Y = 2, Z = 13.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =1, Y = 4, Z = 4}}
go_85[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_85[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_86 = {}
go_86[0] = { Name = "ParedH5", HowManyCmps = 3, Persist = false}
go_86[1] = { Component = "Transform", Coord = {X = -21.5, Y = 2, Z = 15.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =9, Y = 4, Z = 1}}
go_86[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_86[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_87 = {}
go_87[0] = { Name = "ParedH6", HowManyCmps = 3, Persist = false}
go_87[1] = { Component = "Transform", Coord = {X = -22.25, Y = 2, Z = 13.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =7.5, Y = 4, Z = 1.25}}
go_87[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_87[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_88 = {}
go_88[0] = { Name = "ParedH7", HowManyCmps = 3, Persist = false}
go_88[1] = { Component = "Transform", Coord = {X = -25, Y = 2, Z = 9}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 4}}
go_88[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_88[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_89 = {}
go_89[0] = { Name = "ParedH8", HowManyCmps = 3, Persist = false}
go_89[1] = { Component = "Transform", Coord = {X = -23.75, Y = 2, Z = 11.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4.5, Y = 4, Z = .5}}
go_89[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_89[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_90 = {}
go_90[0] = { Name = "ParedH9", HowManyCmps = 3, Persist = false}
go_90[1] = { Component = "Transform", Coord = {X = -21.75, Y = 2, Z = 10.85}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 1.25}}
go_90[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_90[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}


--  HUECOS PARA ZONA I    HUECOS PARA ZONA I    HUECOS PARA ZONA I    HUECOS PARA ZONA I    HUECOS PARA ZONA I    HUECOS PARA ZONA I    HUECOS PARA ZONA I  

go_91 = {}
go_91[0] = { Name = "ParedI1", HowManyCmps = 3, Persist = false}
go_91[1] = { Component = "Transform", Coord = {X = -19.5, Y = 2, Z = 18.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =5, Y = 4, Z = 2}}
go_91[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_91[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_92 = {}
go_92[0] = { Name = "ParedI2", HowManyCmps = 3, Persist = false}
go_92[1] = { Component = "Transform", Coord = {X = -16.55, Y = 2, Z = 19.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =1, Y = 4, Z = 4}}
go_92[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_92[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_93 = {}
go_93[0] = { Name = "ParedI3", HowManyCmps = 3, Persist = false}
go_93[1] = { Component = "Transform", Coord = {X = -19.5, Y = 2, Z = 21.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =7, Y = 4, Z = 1}}
go_93[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_93[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_94 = {}
go_94[0] = { Name = "ParedI4", HowManyCmps = 3, Persist = false}
go_94[1] = { Component = "Transform", Coord = {X = -26.5, Y = 2, Z = 19.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X =7, Y = 4, Z = 5}}
go_94[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_94[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

--  LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2    LIMITES PARTE 2  

go_95 = {}
go_95[0] = { Name = "ParedLimite12", HowManyCmps = 3, Persist = false}
go_95[1] = { Component = "Transform", Coord = {X = 32.5, Y = 2, Z = 15.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 8, Y = 4, Z = 8}}
go_95[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_95[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_96 = {}
go_96[0] = { Name = "ParedLimite13", HowManyCmps = 3, Persist = false}
go_96[1] = { Component = "Transform", Coord = {X = 25.5, Y = 2, Z = 23}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6, Y = 4, Z = 8}}
go_96[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_96[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_97 = {}
go_97[0] = { Name = "ParedLimite14", HowManyCmps = 3, Persist = false}
go_97[1] = { Component = "Transform", Coord = {X = 21.5, Y = 2, Z = 27}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_97[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_97[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_98 = {}
go_98[0] = { Name = "ParedLimite15", HowManyCmps = 3, Persist = false}
go_98[1] = { Component = "Transform", Coord = {X = 19.5, Y = 2, Z = 26}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_98[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_98[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_99 = {}
go_99[0] = { Name = "ParedLimite16", HowManyCmps = 3, Persist = false}
go_99[1] = { Component = "Transform", Coord = {X = 17.75, Y = 2, Z = 24.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7, Y = 4, Z = 1}}
go_99[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_99[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_100 = {}
go_100[0] = { Name = "ParedLimite17", HowManyCmps = 3, Persist = false}
go_100[1] = { Component = "Transform", Coord = {X = 9, Y = 2, Z = 26.675}, Rotation = {X = 0, Y = 2, Z = 0}, Scale = {X = 11, Y = 4, Z = 5}}
go_100[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_100[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_101 = {}
go_101[0] = { Name = "ParedLimite18", HowManyCmps = 3, Persist = false}
go_101[1] = { Component = "Transform", Coord = {X = -19, Y = 2, Z = 29.35}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 45, Y = 4, Z = 10}}
go_101[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_101[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_102 = {}
go_102[0] = { Name = "ParedLimite19", HowManyCmps = 3, Persist = false}
go_102[1] = { Component = "Transform", Coord = {X = -43.5, Y = 2, Z = 19.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 4, Y = 4, Z = 10}}
go_102[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_102[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_103 = {}
go_103[0] = { Name = "ParedLimite20", HowManyCmps = 3, Persist = false}
go_103[1] = { Component = "Transform", Coord = {X = -35.5, Y = 2, Z = 13.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 13, Y = 4, Z = 1.5}}
go_103[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_103[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_104 = {}
go_104[0] = { Name = "ParedLimite21", HowManyCmps = 3, Persist = false}
go_104[1] = { Component = "Transform", Coord = {X =  -29.5, Y = 2, Z = 15.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 3}}
go_104[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_104[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_105 = {}
go_105[0] = { Name = "ParedLimite22", HowManyCmps = 3, Persist = false}
go_105[1] = { Component = "Transform", Coord = {X =  -31, Y = 2, Z = 11.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 3.5}}
go_105[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_105[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

--FirstAidKit part 2
go_106 = {}
go_106[0] = { Name = "FirstAidKit2", HowManyCmps = 4, Persist = false}
go_106[1] = { Component = "Transform", Coord = {X = -8.75, Y = 0, Z = 10.75}, Rotation = {X = 0, Y = 90, Z = 0}, Scale = {X = .8, Y = .2, Z = .8}}
go_106[2] = { Component = "RenderObject", MeshName="firstAid.mesh", Material="botiquin", Visible=true, Shadows=false, RenderingDistance = 50}
go_106[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=10,Depth=1,IsTrigger=true}
go_106[4] = { Component = "FirstAidKitComponent", HealthAmount = 10 }

--Enemigos
go_107 = {}
go_107[0] = { Name = "InvisibleEnemy", HowManyCmps = 3, Persist = false}
go_107[1] = { Component = "Transform", Coord = {X =-25, Y = -100, Z = -1}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 1, Z = 1}}
go_107[2] = { Component = "AudioSource", Route = {"Assets/Audio/MonsterNear.wav", "Assets/Audio/MonsterProwling.wav"}, Stereo = true,
				MinMaxDistance = {Min = 1, Max = 2}, Volume = 0.1, Loops = {-1, 0}, Plays = {true, false}, StopOnDestroy = false}
go_107[3] = { Component = "InvisibleEnemyAIComponent", Speed = 1}

go_108 = {}
go_108[0] = { Name = "Kamikaze1", HowManyCmps = 5, Persist = false}
go_108[1] = { Component = "Transform", Coord = {X = -7.5, Y = 1.5, Z = -16}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_108[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_108[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_108[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_108[5] = { Component = "KamikazeEnemyComponent" }

go_109 = {}
go_109[0] = { Name = "Kamikaze2", HowManyCmps = 5, Persist = false}
go_109[1] = { Component = "Transform", Coord = {X = -36, Y = 1.5, Z = -1.5}, Rotation = {X = 0, Y = 90, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_109[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_109[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_109[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_109[5] = { Component = "KamikazeEnemyComponent" }

go_110 = {}
go_110[0] = { Name = "Kamikaze3", HowManyCmps = 5, Persist = false}
go_110[1] = { Component = "Transform", Coord = {X = 10.5, Y = 1.5, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_110[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_110[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_110[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_110[5] = { Component = "KamikazeEnemyComponent" }

go_111 = {}
go_111[0] = { Name = "Kamikaze4", HowManyCmps = 5, Persist = false}
go_111[1] = { Component = "Transform", Coord = {X = 26, Y = 1.5, Z = 4}, Rotation = {X = 0, Y = 90, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_111[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_111[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_111[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_111[5] = { Component = "KamikazeEnemyComponent" }

go_112 = {}
go_112[0] = { Name = "Kamikaze5", HowManyCmps = 5, Persist = false}
go_112[1] = { Component = "Transform", Coord = {X = 5, Y = 1.5, Z = 19}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_112[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_112[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_112[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_112[5] = { Component = "KamikazeEnemyComponent" }

go_113 = {}
go_113[0] = { Name = "Kamikaze6", HowManyCmps = 5, Persist = false}
go_113[1] = { Component = "Transform", Coord = {X = -13, Y = 1.5, Z = 20.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 2, Z = 2}}
go_113[2] = { Component = "RenderObject", MeshName="kamikaze.mesh", Material="Kamikaze", Visible=true, Shadows=true, RenderingDistance = 50}
go_113[3] = { Component = "RigidBody", Type="Sphere", Mass=9, kinematic = false,
			ConstrainAngle = true, IsTrigger=false, StaticFriction = 0, DynamicFriction = 0, Bounciness = 1}
go_113[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.wav"}, Stereo = true,
			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false, StopOnDestroy = false}
go_113[5] = { Component = "KamikazeEnemyComponent" }

go_114 = {}
go_114[0] = { Name = "Screamer1", HowManyCmps = 5, Persist = false}
go_114[1] = { Component = "Transform", Coord ={X = -14.5, Y = 1, Z = -3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.6, Y =2.4, Z = 1.6}}
go_114[2] = { Component = "RenderObject", MeshName="screamer.mesh", Material="mujer", Visible=true, Shadows=false, RenderingDistance = 50}
go_114[3] = { Component = "RigidBody", Type="Box", Mass=9, Kinematic = false, ConstrainAngle = true, IsTrigger= false}
go_114[4] = { Component = "AudioSource", Route = {"Assets/Audio/girl_sobbing.mp3" ,"Assets/Audio/screaming_girl.mp3"},
			Stereo = true, MinMaxDistance = {Min = 2, Max = 6}, Volume= 1, Play = false}
go_114[5] = { Component = "ScreamerAIEnemyComponent", ShoutIntensityAttack = 1, ShoutIntensityIdle = 0.1,
			  IdleSoundRange = 10, DetectionRange = 7, FollowTime = 4, DyingTime = 3.5, MoveSpeed = 1}

go_115 = {}
go_115[0] = { Name = "Screamer2", HowManyCmps = 5, Persist = false}
go_115[1] = { Component = "Transform", Coord ={X = 23, Y = 1, Z = -13.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale ={X = 1.6, Y =2.4, Z = 1.6}}
go_115[2] = { Component = "RenderObject", MeshName="screamer.mesh", Material="mujer", Visible=true, Shadows=false, RenderingDistance = 50}
go_115[3] = { Component = "RigidBody", Type="Box", Mass=9, Kinematic = false, ConstrainAngle = true, IsTrigger= false}
go_115[4] = { Component = "AudioSource", Route = {"Assets/Audio/girl_sobbing.mp3" ,"Assets/Audio/screaming_girl.mp3"},
			Stereo = true, MinMaxDistance = {Min = 2, Max = 6}, Volume= 1, Play = false}
go_115[5] = { Component = "ScreamerAIEnemyComponent", ShoutIntensityAttack = 1, ShoutIntensityIdle = 0.1,
			  IdleSoundRange = 10, DetectionRange = 7, FollowTime = 4, DyingTime = 3.5, MoveSpeed = 1}

go_116 = {}
go_116[0] = { Name = "Screamer3", HowManyCmps = 5, Persist = false}
go_116[1] = { Component = "Transform", Coord ={X = 22, Y = 1, Z = 24.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.6, Y =2.4, Z = 1.6}}
go_116[2] = { Component = "RenderObject", MeshName="screamer.mesh", Material="mujer", Visible=true, Shadows=false, RenderingDistance = 50}
go_116[3] = { Component = "RigidBody", Type="Box", Mass=9, Kinematic = false, ConstrainAngle = true, IsTrigger= false}
go_116[4] = { Component = "AudioSource", Route = {"Assets/Audio/girl_sobbing.mp3" ,"Assets/Audio/screaming_girl.mp3"},
			Stereo = true, MinMaxDistance = {Min = 2, Max = 6}, Volume= 1, Play = false}
go_116[5] = { Component = "ScreamerAIEnemyComponent", ShoutIntensityAttack = 1, ShoutIntensityIdle = 0.1,
			  IdleSoundRange = 10, DetectionRange = 7, FollowTime = 4, DyingTime = 3.5, MoveSpeed = 1}

--Trampas part 2
go_117 = {}
go_117[0] = { Name = "Trampa2", HowManyCmps = 5, Persist = false}
go_117[1] = { Component = "Transform", Coord = {X = 10, Y = 0.07, Z = 11.4}, Rotation = {X = -90, Y = 90, Z = 0}, Scale = {X = 3.5, Y = 2, Z = 6}}
go_117[2] = { Component = "RenderObject", MeshName="spikes.mesh", Material="pincho", Visible=true, Shadows=true, RenderingDistance = 50}
go_117[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=50,Depth=1,IsTrigger=true}
go_117[4] = { Component = "TrapComponent",EnabledMaterial="Practica1/Red"}
go_117[5] = { Component = "AudioSource", Route = {"Assets/Audio/MetalHit.wav" }, StopOnDestroy = false}

go_118 = {}
go_118[0] = { Name = "Desactivador2", HowManyCmps = 5, Persist = false}
go_118[1] = { Component = "Transform", Coord = {X = 10, Y = 0.2, Z = 9.75 + 1.875 - 0.3}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .3, Y = .4, Z = .3}}
go_118[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Metal", Visible=true, Shadows=true, RenderingDistance = 50}
go_118[3] = { Component = "SphereCollider",Radius=2,IsTrigger=true}
go_118[4] = { Component = "ObjectDeactivatorComponent",ObjName="Trampa2"}
go_118[5] = { Component = "AudioSource", Route = {"Assets/Audio/SwitchSound.mp3" }, StopOnDestroy = false}

-- Last First Aid

go_119 = {}
go_119[0] = { Name = "FirstAidKit3", HowManyCmps = 4, Persist = false}
go_119[1] = { Component = "Transform", Coord = {X = 10.75, Y = 0, Z = 13}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .8, Y = .2, Z = .8}}
go_119[2] = { Component = "RenderObject", MeshName="firstAid.mesh", Material="botiquin", Visible=true, Shadows=false, RenderingDistance = 50}
go_119[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=10,Depth=1,IsTrigger=true}
go_119[4] = { Component = "FirstAidKitComponent", HealthAmount = 10 }

--Bush part 2

go_120 = {}
go_120[0] = { Name = "Bush2", HowManyCmps = 4, Persist = false}
go_120[1] = { Component = "Transform", Coord = {X =  -29.65, Y = 1, Z = 11.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.75, Y = 2, Z = 3.45}}
go_120[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", Visible=true, Shadows=false, RenderingDistance = 50}
go_120[3] = { Component = "SphereCollider", Radius=1,IsTrigger=true}
go_120[4] = { Component = "HideoutComponent" }

go_121 = {}
go_121[0] = { Name = "Bush3", HowManyCmps = 4, Persist = false}
go_121[1] = { Component = "Transform", Coord = {X = 6.35, Y = 1, Z = -11.85}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=2.5, Y = 2, Z = 1}}
go_121[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", Visible=true, Shadows=false, RenderingDistance = 50}
go_121[3] = { Component = "SphereCollider", Radius=1,IsTrigger=true}
go_121[4] = { Component = "HideoutComponent" }

go_122 = {}
go_122[0] = { Name = "Bush4", HowManyCmps = 4, Persist = false}
go_122[1] = { Component = "Transform", Coord = {X = 5.35, Y = 1, Z = 11.1}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2.5, Y = 2, Z = 1}}
go_122[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", Visible=true, Shadows=false, RenderingDistance = 50}
go_122[3] = { Component = "SphereCollider", Radius=1,IsTrigger=true}
go_122[4] = { Component = "HideoutComponent" }

go_123 = {}
go_123[0] = { Name = "Bush5", HowManyCmps = 4, Persist = false}
go_123[1] = { Component = "Transform", Coord = {X = 21.5, Y = 1, Z = 25.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.98, Y = 2, Z = 0.98}}
go_123[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", Visible=true, Shadows=false, RenderingDistance = 50}
go_123[3] = { Component = "SphereCollider", Radius=1,IsTrigger=true}
go_123[4] = { Component = "HideoutComponent" }

go_124 = {}
go_124[0] = { Name = "Techo", HowManyCmps = 3, Persist = false}
go_124[1] = { Component = "Transform", Coord = {X = 0, Y = 4.5, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 200, Y = 1, Z = 150}}
go_124[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_124[3] = { Component = "RigidBody", Type="Box", Static=true, IsTrigger=false}

go_125 = {}
go_125[0] = { Name = "Luz1", HowManyCmps = 2, Persist = false}
go_125[1] = { Component = "Transform", Coord = {X = 23, Y = 3.5, Z = -13.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 1, Z = 1}}
go_125[2] = { Component = "LightComponent", LightType= "POINT", Visible = true, 
											Attenuation = {Range = 200, Constant = 1.0, Linear = 0.30, Quadratic=2},
											Diffuse = {Red = 1, Green= 0, Blue = 0}, 
											Specular = {Red = 1, Green= 0, Blue = 0},
											LightDirection = {X = 0, Y = 0, Z = 0},
											Intensity=5}

go_126 = {}
go_126[0] = { Name = "Luz2", HowManyCmps = 2, Persist = false}
go_126[1] = { Component = "Transform", Coord = {X = 30, Y = 3.5, Z = 8.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 1, Z = 1}}
go_126[2] = { Component = "LightComponent", LightType= "POINT", Visible = true, 
											Attenuation = {Range = 200, Constant = 1.0, Linear = 0.30, Quadratic=2},
											Diffuse = {Red = 1, Green= 1, Blue = 1}, 
											Specular = {Red = 1, Green= 1, Blue = 1},
											LightDirection = {X = 0, Y = 0, Z = 0},
											Intensity=5}

go_127 = {}
go_127[0] = { Name = "Luz3", HowManyCmps = 2, Persist = false}
go_127[1] = { Component = "Transform", Coord = {X = 4, Y = 3.5, Z = 24.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 1, Z = 1}}
go_127[2] = { Component = "LightComponent", LightType= "POINT", Visible = true, 
											Attenuation = {Range = 200, Constant = 1.0, Linear = 0.30, Quadratic=2},
											Diffuse = {Red = 1, Green= 1, Blue = 1}, 
											Specular = {Red = 1, Green= 1, Blue = 1},
											LightDirection = {X = 0, Y = 0, Z = 0},
											Intensity=5}

--Luces

--go_2 = {}
--go_2[0] = { Name = "Screamer", HowManyCmps = 5, Persist = false}
--go_2[1] = { Component = "Transform", Coord = {X = 0, Y = 5, Z = -30}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 0.1, Y = 0.1, Z = 0.1}}
--go_2[2] = {	Component = "RenderObject", MeshName="ogrehead.mesh", Material="Practica1/Red", 
--			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
--			Visible=true, Shadows=false, RenderingDistance = 1000}
--go_2[3] = { Component = "RigidBody", Type="Box", Mass=9, Width=10, Depth=10, Height=10, Kinematic = false,
--			ConstrainAngle = true, IsTrigger= false}
--go_2[4] = { Component = "AudioSource", Route = {"Assets/Audio/woman_cry.mp3" ,"Assets/Audio/baby_crying.mp3"},
--			Stereo = true, MinMaxDistance = {Min = 2, Max = 6}, Volume= 1, Play = false}
--go_2[5] = { Component = "ParticleSystem", Path="Assets/ParticleSystems/Practica2.particle"}
--go_2[5] = { Component = "ScreamerAIEnemyComponent", ShoutIntensityAttack = 1, ShoutIntensityIdle = 0.1,
--			DetectionRange = 30, FollowTime = 5, DyingTime = 4, MoveSpeed = 3}
			
--go_3 = {}
--go_3[0] = { Name = "InvisibleEnemy", HowManyCmps = 4, Persist = false}
--go_3[1] = { Component = "Transform", Coord = {X = -15, Y = 5, Z = -30}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 0.1, Y = 0.1, Z = 0.1}}
--go_3[2] = {	Component = "RenderObject", MeshName="ogrehead.mesh", Material="Practica1/Red", 
--			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
--			Visible=true, Shadows=false, RenderingDistance = 1000}
--go_3[3] = { Component = "AudioSource", Route = {"Assets/Audio/ProtoDarkMaze_Menu.mp3", "Assets/Audio/goat_cry.mp3"}, Stereo = true,
--			MinMaxDistance = {Min = 2, Max = 6}, Volume= 10, Play = false}
--go_3[4] = { Component = "InvisibleEnemyAIComponent"}

--go_4 = {}
--go_4[0] = { Name = "Kamikaze", HowManyCmps = 5, Persist = false}
--go_4[1] = { Component = "Transform", Coord = {X = 25, Y = 5, Z = -40}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 0.1, Y = 0.1, Z = 0.1}}
--go_4[2] = {	Component = "RenderObject", MeshName="ogrehead.mesh", Material="Practica1/Red", 
--			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
--			Visible=true, Shadows=false, RenderingDistance = 1000}
--go_4[3] = { Component = "RigidBody", Type="Box", Mass=9, Width=10, Depth=10, Height=10, kinematic = true,
--			ConstrainAngle = true, IsTrigger=false}
---go_4[4] = { Component = "AudioSource", Route = {"Assets/Audio/kamikaze_scream.wav" ,"Assets/Audio/kamikaze_explosion.mp3"}, Stereo = true,
--			MinMaxDistance = {Min = 2, Max = 6}, Volume= 15, Play = false}
--go_4[5] = { Component = "KamikazeEnemyComponent" }

--Luz direccional
-- go_2 = {}
-- go_2[0] = { Name = "LuzDireccional", HowManyCmps = 2, Persist = false}
-- go_2[1] = { Component = "Transform", Coord = {X = 0, Y = 500, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}}
-- go_2[2] = { Component = "LightComponent", LightType= "DIRECTIONAL", Visible = true,
-- 		    Diffuse = {Red = 0.7, Green= 0.5, Blue = 0.5}, 
-- 			Specular = {Red = 1, Green= 1, Blue = 1},
-- 			LightDirection = {X = -1.3, Y = -1,Z = 0}}