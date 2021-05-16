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

HowManyGameObjects = 51
-- Player
go_0 = {}
go_0[0] = { Name = "Player", HowManyCmps = 9, Persist = false}
go_0[1] = { Component = "Transform", Coord = {X = -5, Y = 40, Z = -5}, Rotation = {X = -90, Y = 0, Z = 0}, Scale = {X = 1, Y = 2, Z = 1}}
go_0[9] = { Component = "PlayerMovementComponent", PlayerHeight = 2, CameraSpeed=35 }
--go_0[2] = { Component = "RigidBody", Type="Box", Mass=10, Kinematic = false, ConstrainAngle = true, IsTrigger=false}
go_0[2] = { Component = "Camera", Plane = {Near = 0.01}, Compositors = {"JugadorVisionWeak", false, "JugadorVisionStrong", false, "JugadorVisionInjured", false}, SlaveRotation=true}
go_0[3] = { Component = "Listener", ListenerNumber = 0, Velocity = {X = 0, Y = 0, Z = 0} }
go_0[4] = { Component = "PlayerInteractiveComponent" }
go_0[5] = { Component = "PlayerKeysComponent"}
go_0[6] = { Component = "HealthComponent", HP=100 }
go_0[7] = { Component = "LightComponent", LightType= "POINT", Visible = true,
										Diffuse = {Red = 1, Green= 1, Blue = 1}, 
									    Specular = {Red = 1, Green= 1, Blue = 1},																				
										LightDirection = {X = 0, Y = 0, Z = -1},
									    Intensity= 20}
										
										-- { Component = "LightComponent", LightType= "POINT", Visible = true, 
                                        -- Attenuation = {Range = 500, Constant = 1.0, Linear = 0.30, Quadratic=2},
                                        -- Diffuse = {Red = 1, Green= 1, Blue = 1}, 
                                        -- Specular = {Red = 1, Green= 1, Blue = 1},
                                        -- LightDirection = {X = 0, Y = 0, Z = 0},
                                        -- Intensity=5}
go_0[8] = { Component = "PlayerVisibilityComponent" }


-- Suelo
go_1 = {}
go_1[0] = { Name = "Suelo", HowManyCmps = 3, Persist = false}
go_1[1] = { Component = "Transform", Coord = {X = 0, Y = -0.5, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 200, Y = 1, Z = 150}}
go_1[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_1[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

-- FirstAidKit
go_2 = {}
go_2[0] = { Name = "FirstAidKit", HowManyCmps = 4, Persist = false}
go_2[1] = { Component = "Transform", Coord = {X = 0, Y = -50, Z = -50}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .5, Y = .01, Z = .5}}
go_2[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
						RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
						Visible=true, Shadows=false, RenderingDistance = 1000}
go_2[3] = { Component = "BoxCollider", Type="Box",Width=8,Height=8,Depth=8,IsTrigger=true}
go_2[4] = { Component = "FirstAidKitComponent", HealthAmount = 10 }


go_3 = {}
go_3[0] = { Name = "Key", HowManyCmps = 4, Persist = false}
go_3[1] = { Component = "Transform", Coord = {X = -10, Y = -50, Z = 150}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .3, Y =.3, Z = .3}}
go_3[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
						RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
						Visible=true, Shadows=false, RenderingDistance = 1000}
go_3[3] = { Component = "SphereCollider",Radius=10,IsTrigger=true}
go_3[4] = { Component = "KeyComponent" }

go_4 = {}
go_4[0] = { Name = "Puerta", HowManyCmps = 5, Persist = false}
go_4[1] = { Component = "Transform", Coord = {X = 0, Y = -50, Z = 190}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .4, Y = .7, Z = .4}}
go_4[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
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

-- Bush
go_6 = {}
go_6[0] = { Name = "Bush1", HowManyCmps = 4, Persist = false}
go_6[1] = { Component = "Transform", Coord = {X = 0, Y = -50, Z = -100}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .3, Y = .8, Z = .3}}
go_6[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Bush", 
						RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=0, Y=0, Z=0},
						Visible=true, Shadows=false, RenderingDistance = 1000}
go_6[3] = { Component = "SphereCollider", Radius=50,IsTrigger=true}
go_6[4] = { Component = "HideoutComponent" }

-- Trampa
go_7 = {}
go_7[0] = { Name = "Trampa1", HowManyCmps = 4, Persist = false}
go_7[1] = { Component = "Transform", Coord = {X = 0, Y = 650, Z = 100}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .5, Y = .1, Z = .5}}
go_7[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Yellow", 
			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_7[3] = { Component = "BoxCollider", Type="Box",Width=1,Height=50,Depth=1,IsTrigger=false}
go_7[4] = { Component = "TrapComponent",EnabledMaterial="Practica1/Red"}

-- Desactivador
go_8 = {}
go_8[0] = { Name = "Desactivador1", HowManyCmps = 4, Persist = false}
go_8[1] = { Component = "Transform", Coord = {X = 0, Y = -50, Z = 50}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = .10, Y = .10, Z = .05}}
go_8[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Red", 
			RotateAngle = 0, Rotate={X=0, Y=0, Z=0}, Scale = {X=1, Y=1, Z=1}, LookAt ={X=1, Y=1, Z=1},
			Visible=true, Shadows=true, RenderingDistance = 1000}
go_8[3] = { Component = "SphereCollider",Radius=50,IsTrigger=true}
go_8[4] = { Component = "ObjectDeactivatorComponent",ObjName="Trampa1"}


-- Paredes
--  SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN    SPAWN  
go_9 = {}
go_9[0] = { Name = "ParedS1", HowManyCmps = 3, Persist = false}
go_9[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=5, Y = 4, Z = 5}}
go_9[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_9[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_10 = {}
go_10[0] = { Name = "ParedS2", HowManyCmps = 3, Persist = false}
go_10[1] = { Component = "Transform", Coord = {X = 5.75, Y = 2, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7.5, Y = 4, Z = 6}}
go_10[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_10[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_11 = {}
go_11[0] = { Name = "ParedS3", HowManyCmps = 3, Persist = false}
go_11[1] = { Component = "Transform", Coord = {X = 0, Y = 2, Z = 4.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 4}}
go_11[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_11[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_12 = {}
go_12[0] = { Name = "ParedS4", HowManyCmps = 3, Persist = false}
go_12[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_12[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_12[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

-- ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A ZONA A

go_13 = {}
go_13[0] = { Name = "ParedA1", HowManyCmps = 3, Persist = false}
go_13[1] = { Component = "Transform", Coord = {X = -1.5, Y = 0, Z = -5.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=9, Y = 4, Z = 1}}
go_13[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_13[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_14 = {}
go_14[0] = { Name = "ParedA2", HowManyCmps = 3, Persist = false}
go_14[1] = { Component = "Transform", Coord = {X = 6.25, Y = 0, Z = -6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 3}}
go_14[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_14[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_15 = {}
go_15[0] = { Name = "ParedA3", HowManyCmps = 3, Persist = false}
go_15[1] = { Component = "Transform", Coord = {X = 1, Y = 0, Z = -7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 0.75}}
go_15[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_15[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_16 = {}
go_16[0] = { Name = "ParedA4", HowManyCmps = 3, Persist = false}
go_16[1] = { Component = "Transform", Coord = {X = -4.25, Y = 0, Z = -7}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3.5, Y = 4, Z = 2}}
go_16[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_16[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_17 = {}
go_17[0] = { Name = "ParedA5", HowManyCmps = 3, Persist = false}
go_17[1] = { Component = "Transform", Coord = {X = -4.25, Y = 0, Z = -10.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3.5, Y = 4, Z = 2}}
go_17[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_17[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_18 = {}
go_18[0] = { Name = "ParedA6", HowManyCmps = 3, Persist = false}
go_18[1] = { Component = "Transform", Coord = {X = -0.5, Y = 0, Z = -11.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=11, Y = 4, Z = 1}}
go_18[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_18[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_19 = {}
go_19[0] = { Name = "ParedA7", HowManyCmps = 3, Persist = false}
go_19[1] = { Component = "Transform", Coord = {X = 0.5, Y = 0, Z = -8.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 2}}
go_19[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_19[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_20 = {}
go_20[0] = { Name = "ParedA8", HowManyCmps = 3, Persist = false}
go_20[1] = { Component = "Transform", Coord = {X = 4.5, Y = 0, Z = -10.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_20[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_20[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}


--- ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B ZONA B

go_21 = {}
go_21[0] = { Name = "ParedB1", HowManyCmps = 3, Persist = false}
go_21[1] = { Component = "Transform", Coord = {X = 11.75, Y = 0, Z = -10.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4.5, Y = 4, Z = 3}}
go_21[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_21[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_22 = {}
go_22[0] = { Name = "ParedB2", HowManyCmps = 3, Persist = false}
go_22[1] = { Component = "Transform", Coord = {X = 18.625, Y = 0, Z = -10.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=5.75, Y = 4, Z = 3}}
go_22[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_22[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_23 = {}
go_23[0] = { Name = "ParedB3", HowManyCmps = 3, Persist = false}
go_23[1] = { Component = "Transform", Coord = {X = 12.75, Y = 0, Z = -6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6.5, Y = 4, Z = 2.8}}
go_23[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_23[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_24 = {}
go_24[0] = { Name = "ParedB4", HowManyCmps = 3, Persist = false}
go_24[1] = { Component = "Transform", Coord = {X = 19.5, Y = 0, Z = -7.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 4.5}}
go_24[2] = {Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo",Visible=true, Shadows=true, RenderingDistance = 1000}
go_24[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}


--  ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C    ZONA C  

go_25 = {}
go_25[0] = { Name = "ParedC1", HowManyCmps = 3, Persist = false}
go_25[1] = { Component = "Transform", Coord = {X = 12.5, Y = 2, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 6}}
go_25[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_25[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_26 = {}
go_26[0] = { Name = "ParedC2", HowManyCmps = 3, Persist = false}
go_26[1] = { Component = "Transform", Coord = {X = 10.5, Y = 2, Z = 6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6, Y = 4, Z = 3}}
go_26[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_26[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_27 = {}
go_27[0] = { Name = "ParedC3", HowManyCmps = 3, Persist = false}
go_27[1] = { Component = "Transform", Coord = {X = 17.5, Y = 2, Z = -0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 4}}
go_27[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_27[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_28 = {}
go_28[0] = { Name = "ParedC4", HowManyCmps = 3, Persist = false}
go_28[1] = { Component = "Transform", Coord = {X = 17.5, Y = 2, Z = 7.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 4}}
go_28[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_28[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_29 = {}
go_29[0] = { Name = "ParedC5", HowManyCmps = 3, Persist = false}
go_29[1] = { Component = "Transform", Coord = {X = 19, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 4}}
go_29[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_29[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_30 = {}
go_30[0] = { Name = "ParedC6", HowManyCmps = 3, Persist = false}
go_30[1] = { Component = "Transform", Coord = {X = 15.5, Y = 2, Z = 2}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 1}}
go_30[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_30[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_31 = {}
go_31[0] = { Name = "ParedC7", HowManyCmps = 3, Persist = false}
go_31[1] = { Component = "Transform", Coord = {X = 15.5, Y = 2, Z = 5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1, Y = 4, Z = 1}}
go_31[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_31[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}


--  ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D    ZONA D  

go_32 = {}
go_32[0] = { Name = "ParedD1", HowManyCmps = 3, Persist = false}
go_32[1] = { Component = "Transform", Coord = {X = 24.5, Y = 2, Z = -1.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_32[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_32[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_33 = {}
go_33[0] = { Name = "ParedD2", HowManyCmps = 3, Persist = false}
go_33[1] = { Component = "Transform", Coord = {X = 25.5, Y = 2, Z = -3.75}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=4, Y = 4, Z = 2.5}}
go_33[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_33[3] = { Component = "BoxCollider", Type="Box",IsTrigger=false}

go_34 = {}
go_34[0] = { Name = "ParedD3", HowManyCmps = 3, Persist = false}
go_34[1] = { Component = "Transform", Coord = {X = 23.25, Y = 2, Z = 6.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=3, Y = 4, Z = 6}}
go_34[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_34[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_35 = {}
go_35[0] = { Name = "ParedD4", HowManyCmps = 3, Persist = false}
go_35[1] = { Component = "Transform", Coord = {X = 24.75, Y = 2, Z = 2.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=6, Y = 4, Z = 2}}
go_35[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 1000}
go_35[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

--  ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E    ZONA E  
go_36 = {}
go_36[0] = { Name = "ParedE1", HowManyCmps = 3, Persist = false}
go_36[1] = { Component = "Transform", Coord = {X = -17.5, Y = 0, Z = -1.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2.5}}
go_36[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_36[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_37 = {}
go_37[0] = { Name = "ParedE2", HowManyCmps = 3, Persist = false}
go_37[1] = { Component = "Transform", Coord = {X = -15.5, Y = 0, Z = -3}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 1.5}}
go_37[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_37[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_38 = {}
go_38[0] = { Name = "ParedE3", HowManyCmps = 3, Persist = false}
go_38[1] = { Component = "Transform", Coord = {X = -21, Y = 0, Z = -8}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 5.5}}
go_38[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_38[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_39 = {}
go_39[0] = { Name = "ParedE4", HowManyCmps = 3, Persist = false}
go_39[1] = { Component = "Transform", Coord = {X = -14.75, Y = 0, Z = -7}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3.5, Y = 4, Z = 7.5}}
go_39[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_39[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_40 = {}
go_40[0] = { Name = "ParedE5", HowManyCmps = 3, Persist = false}
go_40[1] = { Component = "Transform", Coord = {X = -23.5, Y = 0, Z = -4}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 5, Y = 4, Z = 3}}
go_40[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_40[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_41 = {}
go_41[0] = { Name = "ParedE6", HowManyCmps = 3, Persist = false}
go_41[1] = { Component = "Transform", Coord = {X = -21.75, Y = 0, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 1.5, Y = 4, Z = 5}}
go_41[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_41[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_42 = {}
go_42[0] = { Name = "ParedE7", HowManyCmps = 3, Persist = false}
go_42[1] = { Component = "Transform", Coord = {X = -20.55, Y = 0, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3.75, Y = 4, Z = 2}}
go_42[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_42[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_43 = {}
go_43[0] = { Name = "ParedE8", HowManyCmps = 3, Persist = false}
go_43[1] = { Component = "Transform", Coord = {X = -30, Y = 0, Z = 2.25}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 15, Y = 4, Z = 4.5}}
go_43[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_43[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}


-- ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G ZONA G 

go_44 = {}
go_44[0] = { Name = "ParedG1", HowManyCmps = 3, Persist = false}
go_44[1] = { Component = "Transform", Coord = {X = -11, Y = 0, Z = 11}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 9, Y = 4, Z = 3}}
go_44[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_44[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_45 = {}
go_45[0] = { Name = "ParedG2", HowManyCmps = 3, Persist = false}
go_45[1] = { Component = "Transform", Coord = {X = -14, Y = 0, Z = 18.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 3, Y = 4, Z = 12}}
go_45[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_45[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_46 = {}
go_46[0] = { Name = "ParedG3", HowManyCmps = 3, Persist = false}
go_46[1] = { Component = "Transform", Coord = {X = -10, Y = 0, Z = 24}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 7, Y = 4, Z = 5}}
go_46[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_46[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_47 = {}
go_47[0] = { Name = "ParedG4", HowManyCmps = 3, Persist = false}
go_47[1] = { Component = "Transform", Coord = {X = -11.5, Y = 0, Z = 20.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_47[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_47[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_48 = {}
go_48[0] = { Name = "ParedG5", HowManyCmps = 3, Persist = false}
go_48[1] = { Component = "Transform", Coord = {X = -7.5, Y = 0, Z = 20.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_48[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_48[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_49 = {}
go_49[0] = { Name = "ParedG6", HowManyCmps = 3, Persist = false}
go_49[1] = { Component = "Transform", Coord = {X = -5.5, Y = 0, Z = 12.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 6}}
go_49[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_49[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_50 = {}
go_50[0] = { Name = "ParedG7", HowManyCmps = 3, Persist = false}
go_50[1] = { Component = "Transform", Coord = {X = -7.5, Y = 0, Z = 16.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 6, Y = 4, Z = 2}}
go_50[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_50[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}