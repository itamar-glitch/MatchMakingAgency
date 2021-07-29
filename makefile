executable_1: assignment2.o Client.o MatchMakingAgency.o String.o Menu.o
	g++ assignment2.o Client.o MatchMakingAgency.o String.o Menu.o -o executable_2

assignment1.o: assignment2.cpp
	g++ -c assignment2.cpp

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
