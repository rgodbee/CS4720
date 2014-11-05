#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// a flight stop
typedef struct flightList_location
{
  int airportCode;
  struct flightList_location* next;
  struct flightList_location* prev;
} location;

// the flight path
typedef struct
{
  location* front;
  location* rear;
  int size;
} flightList;

// create a flight stop
location* create_location (int airportCode)
{
  location* n = malloc (sizeof (location));
  n -> airportCode = airportCode;
  n -> next = NULL;
  n -> prev = NULL;
  return n;
}

// create a flight path
flightList* create_flightList()
{
  flightList* l = malloc (sizeof(flightList));
  l -> front = NULL;
  l -> rear = NULL;
  l -> size = 0;
  return l;
}

// determin if a flight path is empty
int is_empty (const flightList* l)
{
  assert (l != NULL);
  return l -> size == 0;
}

// calculate the number of stops in the flight path
int size (const flightList* l)
{
  assert (l != NULL);
  return l -> size;
}

// add a flight stop at the end of the flight list
void append (flightList* l, int airportCode)
{
  assert (l != NULL);
  location* n = create_location (airportCode);
  if (is_empty (l))
  {
   l -> front = n;
   l -> rear = n;
  }
  else
  {
    n -> prev = l-> rear;
    l -> rear -> next = n;
    l -> rear = n;
  }
  l -> size++;
}

// add a flight stop to the beginning of the flight list
void prepend (flightList* l, int airportCode)
{
  assert (l != NULL);
  location* n = create_location (airportCode);
  if (is_empty (l))
  {
    l -> front = n;
    l -> rear = n;
  }
  else
  {
    n -> next = l -> front;
    l -> front -> prev = n;
    l -> front = n;
  }
  l -> size++;
}

// add a flight stop to a particular point in the flight list
int insert (flightList* l, int airportCode, int index)
{
  assert (l != NULL);
  int result = index >= 0 && index <= size(l);
  if (result)
  {
    if (index == 0)
	prepend (l, airportCode);
    else if (index == size(l))
      append (l, airportCode);
    else
    {
      location* temp = l -> front;
      int i;
      for (i = 0; i < index - 1; i++)
		temp = temp -> next;
      location* n = create_location (airportCode);
      n -> next = temp -> next;
      n -> prev = temp;
      n -> next -> prev = n;
      temp -> next = n;
      l -> size++;
    }
  }
  return result;
}

// remove a given indexed flight stop from the flight list
int remove_from_flightList (flightList* l, int index)
{
  assert (l != NULL);
  int result = index >= 0 && index < size(l);
  if (result)
  {
    location* n;
    if (index == 0)
    {
      n = l -> front;
      l -> front = n -> next;
      l -> front -> prev = NULL;
      if (l -> front == NULL)
	l -> rear = NULL;
    }
    else
    {
      location* temp = l -> front;
      int i;
      for (i = 0; i < index - 1; i++)
	temp = temp -> next;
      n = temp -> next;
      n -> next -> prev = temp;
      temp -> next = n -> next;
      if (temp -> next == NULL)
      {
	l -> rear -> prev = NULL;
	l -> rear = temp;
      }
    }
    free (n);
    l -> size--;
  }
  return result;
}

// get a flight stop from a given index
void* get (const flightList* l, int index)
{
 assert (l != NULL);
 void* result = NULL;
 if (index >= 0 && index < size(l))
 {
   location* temp = l -> front;
   int i;
   for (i = 0; i < index; i++)
     temp = temp -> next;
   result = (int)temp -> airportCode;
 }
 return result;
}

// change the order of a flight stop in the flight list
int set (flightList* l, int airportCode, int index)
{
  assert (l != NULL);
  int result = index >= 0 && index < size(l);
  if (result)
  {
    location* temp = l -> front;
    int i;
    for (i = 0; i < index; i++)
      temp = temp -> next;
    temp -> airportCode = airportCode;
  }
  return result;
}

// delete a flight list
void delete_flightList (flightList* l)
{
  assert (l != NULL);
  location* n = l -> front;
  int i;
  for (i = 0; i < size(l); i++)
  {
    location* temp = n;
    n -> prev = NULL;
    n = n -> next;
    free (temp);
  }
  free (l);
}

int main()
{
	
	flightList* toTheMoon = create_flightList();
	prepend(toTheMoon, 1110);
	append(toTheMoon, 1524);
	append(toTheMoon, 5820);
	// will remove newYork from the flight list
	int result = remove_from_flightList(toTheMoon, 1);
	append(toTheMoon, 99983);
	int tripDistance = size(toTheMoon);
	printf("Number of stops:\t%d\n", tripDistance);
	return 0;
}