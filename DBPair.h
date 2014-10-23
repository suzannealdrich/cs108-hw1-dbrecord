// DBPair.h#pragma once	// prevents multiple-include problems/* DBPair stores two C strings -- an attribute and a value.  The strings are set initially via the constructor and may be changed by SetAttributeValue(). The DBPair always does its own memory allocation so the client retains ownership of the any parameter memory.  The Contains() operation is specialized to support DBRecord operations -- Contains() is true if the criteria attribute is equal (strcmp) to the receiver attribute, and the criteria value is a substring (strstr) of the receiver value. A criteria string of exactly "*" matches anything.  The default constructor can put the DBPair in a special "null" state where both strings are NULL. (This state is, unfortunately, necessary so that we can allocate arrays of DBPairs.)  Most operations work normally when the DBPair is in its null state. The only clarifications are: -Write() prints nothing if the receiver is null -Contains() returns false if either the receiver or the criteria is null.*/// The following is necessary because we use istream and ostream// in our headers#include <iostream.h>class DBPair {	public:		// Constructors and Destructor		DBPair();		DBPair(const char* _attribute, const char* _value);		virtual ~DBPair();				// Change both strings by passing new C string values.		void SetAttributeValue(const char* _attribute, const char* _value);				// Test if the receiver contains the given pair		bool Contains(const DBPair& criteria) const;				// Write to the given stream. The Pair is written on one line		// with the attribute first, followed by a whitespace character,		// followed by the value, followed by the '\n'.		void Write(ostream& out) const;		// Read in one line in the format written by Write() and set		// the receiver accordingly.		void Read(istream& in);			private:		char* attribute;		char* value;				// Declaring these as private prevents any client		// from accidentally using "=" on this object.		void operator=(const DBPair&);		DBPair(const DBPair&);				void ClearAttributeValue();};// This is the bound on the length of a single string.// It's handy for Read() to be able to assume such a bound.// This bound is used during reading, but the storage// of the strings is fitted to the actual strings.const int MAX_STRING_LEN = 1000;// This is a handy place to put the DEBUG_NEW switch// so all the other files see it#define DEBUG_NEW 2#include <DebugNew.h>