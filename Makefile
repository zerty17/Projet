CXX =g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall
LDLIBS += -lm
all: testVecteur testBalle integrateurtest2 testPendule
testVecteur: Vecteur.o testVecteur.o 
	g++   -o testVecteur Vecteur.o testVecteur.o
testBalle: Balle.o testBalle.o Vecteur.o ChampForces.o objetmobile.o
	g++ -o testBalle testBalle.o Balle.o Vecteur.o ChampForces.o objetmobile.o
testPendule: testPendule.o Vecteur.o objetmobile.o integrateur.o Balle.o integrateureuler.o ChampForces.o Pendule.o
	g++ -o testPendule testPendule.o Vecteur.o objetmobile.o integrateur.o integrateureuler.o ChampForces.o Pendule.o
integrateurtest2: Vecteur.o objetmobile.o integrateur.o integrateurtest2.o integrateureuler.o ChampForces.o
	g++ -o integrateurtest2 integrateurtest2.o Vecteur.o objetmobile.o integrateur.o Balle.o integrateureuler.o ChampForces.o
#~ testObstacle: testObstacle.o Vecteur.o objetmobile.o integrateur.o Balle.o integrateurtest2.o integrateureuler.o ChampForces.o obstacle.o
#~ 	g++ -o testObstacle testObstacle.o Vecteur.o objetmobile.o integrateur.o Balle.o integrateurtest2.o integrateureuler.o ChampForces.o obstacle.o
Vecteur.o: Vecteur.cc Vecteur.h ChampForces.h
	g++ -c Vecteur.cc ChampForces.cc
testVecteur.o: testVecteur.cc
	g++ -c testVecteur.cc

testBalle.o: testBalle.cc 
	g++ -c testBalle.cc
integrateurtest2.o: integrateurtest2.cc
	g++ -c integrateurtest2.cc
#~ testObstacle.o: testObstacle.cc
#~ 	g++ -c testObstacle.cc
testPendule.o: testPendule.cc
	g++ -c testPendule.cc
	
Balle.o: Balle.cc Balle.h
	g++ -c Balle.cc
ChampForces.o: ChampForces.cc ChampForces.h
	g++ -c ChampForces.cc
objetmobile.o: objetmobile.h objetmobile.cc
	g++ -c objetmobile.cc
integrateur.o: integrateur.h integrateur.cc
	g++ -c integrateur.cc
integrateureuler.o: integrateureuler.h integrateureuler.cc
	g++ -c integrateureuler.cc
Pendule.o: Pendule.h Pendule.cc
	g++ -c Pendule.cc
obstacle.o: obstacle.h obstacle.cc
	g++ -c obstacle.cc
	


clean:
	rm *.o Vecteur.exe
	
	
	
## g++ -MM *.cc
