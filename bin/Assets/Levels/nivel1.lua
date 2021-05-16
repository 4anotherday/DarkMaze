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

HowManyGameObjects = 13--21--16
-- Player
go_0 = {}
go_0[0] = { Name = "Player", HowManyCmps = 8, Persist = false}
go_0[1] = { Component = "Transform", Coord = {X = 0, Y = 50, Z = 0}, Rotation = {X = -90, Y = 0, Z = 0}, Scale = {X = 1, Y = 2, Z = 1}}
--go_0[2] = { Component = "PlayerMovementComponent", PlayerHeight = 2, CameraSpeed=35 }
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

--Enemigos
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
go_9 = {}
go_9[0] = { Name = "ParedS1", HowManyCmps = 3, Persist = false}
go_9[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 0}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X=5, Y = 4, Z = 5}}
go_9[2] = {	Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_9[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_10 = {}
go_10[0] = { Name = "ParedS2", HowManyCmps = 3, Persist = false}
go_10[1] = { Component = "Transform", Coord = {X = 5.5, Y = 2, Z = 0.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 8, Y = 4, Z = 6}}
go_10[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_10[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_11 = {}
go_11[0] = { Name = "ParedS3", HowManyCmps = 3, Persist = false}
go_11[1] = { Component = "Transform", Coord = {X = 0, Y = 2, Z = 4}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 10, Y = 4, Z = 3}}
go_11[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_11[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}

go_12 = {}
go_12[0] = { Name = "ParedS4", HowManyCmps = 3, Persist = false}
go_12[1] = { Component = "Transform", Coord = {X = -5, Y = 2, Z = 3.5}, Rotation = {X = 0, Y = 0, Z = 0}, Scale = {X = 2, Y = 4, Z = 2}}
go_12[2] = { Component = "RenderObject", MeshName="cube.mesh", Material="Practica1/Suelo", Visible=true, Shadows=true, RenderingDistance = 250}
go_12[3] = { Component = "BoxCollider", Type="Box", IsTrigger=false}
