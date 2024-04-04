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
            int d = newIndex - i;
            // 4 2 5 7 1
            // 4 2 5 1 7
            // 7 4 2 5 1
            // 4 7 2 5 1
            // 
            if (d>0) {
                for (size_t j = i; j != newIndex; ++j) {
                    Type v = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = v;
                }
            }
            else
                for (size_t j = i; j != newIndex; --j) {
                    Type v = vec[j];
                    vec[j] = vec[j - 1];
                    vec[j - 1] = v;
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
    a.shift(-7,2);
    a.print();
}