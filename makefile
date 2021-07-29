executable_1: main.o Client.o MatchMakingAgency.o String.o Menu.o
	g++ main.o Client.o MatchMakingAgency.o String.o Menu.o -o executable_2

main.o: main.cpp
	g++ -c main.cpp

TwoDigits.o: Client.cpp
	g++ -c Client.cpp

Fraction.o: MatchMakingAgency.cpp
	g++ -c MatchMakingAgency.cpp

String.o: String.cpp
	g++ -c String.cpp

Menu.o: Menu.cpp
	g++ -c Menu.cpp

clean:
	rm *.o executable_2
