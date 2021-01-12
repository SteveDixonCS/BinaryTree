#ifndef DATATYPE_H
#define DATATYPE_H

enum Comparison
{
	GREATER,LESS,EQUAL
};

class DataType
{
 public:
  DataType();
  void print();
  void initialize(int number);
  int getValue() const;
  void setValue(int value);
  Comparison compareTo(DataType &item);

 private:
  int value;
};

#endif
