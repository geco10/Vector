#include<iostream>
#include<vector>

namespace mod {
    template<typename Type>
	class vector :public std::vector<Type> {
        mod::vector<Type>& vec = *this;
    public:
        void print() {
            for (int i = 0; i < this->size(); i++)
            {
                std::cout << this->operator[](i)<<" ";
            }
        }
        double  average() {
            int c=0;
            int sum = 0;
            for (int i = 0; i < vec.size(); ++i,c++) {
                sum += vec[i];
            }
            return sum / c;
        }
		void shift(int s, int i) {
            std::vector<Type>& vec = *this;
            if (this->empty() || i < 0 || i >= this->size()) {
                throw "invalid input";
            }

            int newIndex = (i + s) % this->size();

            // 4 5 7 8 9 8 3 3 5 2 1 
            for (size_t j = i; j !=newIndex; ++j) {
                Type v = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = v;
            }
        }
	};
};
int main() {
    mod::vector <int>a;
    a.push_back(4);
    a.push_back(2);
    a.push_back(9);
    a.push_back(5);
    a.print();
    puts("");
    a.shift(3,1);
    a.print();
}