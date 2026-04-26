# Makefile for Hotel Management System

CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = hotel.exe
SOURCES = main.cpp Person.cpp Guest.cpp Employee.cpp Manager.cpp Room.cpp Bill.cpp RoomBill.cpp ServiceBill.cpp Payment.cpp CashPayment.cpp OnlinePayment.cpp CardPayment.cpp Booking.cpp Hotel.cpp Authentication.cpp Feature.cpp Status.cpp Review.cpp Cafe.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
