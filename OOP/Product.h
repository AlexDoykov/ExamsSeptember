class Product
{
private:
	char* name;
	int number;
	double price;
public:
	void setName(const char*);
	
	char const * getName() const;

	int getNumber() const;

	void setNumber(int);

	double getPrice() const;
	
	void setPrice(double);

	Product(int);
	
	Product(const Product&);

	Product& operator = (const Product&);

	friend std::istream& operator >> (std::ifstream&, Product&);
	friend std::ostream& operator << (std::ostream&, const Product&);

	~Product();
};