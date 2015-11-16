all:
	g++ main.cpp WallPost.cpp WallpostResponse.cpp Wall.cpp User.cpp UserNetwork.cpp BagofFriends.cpp -o DelPlayaNetwork

clean:
	rm -rf DelPlayaNetwork
