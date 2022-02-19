#include <iostream>
#include <chrono>
#define M 10000
#define N 100000
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
int BinarySearch(int* mas, int l, int n, int k)
{
	if (k < mas[l])
		return -1;
	if (k == mas[l])
		return 0;
	if (k > mas[n])
		return -1;

	int a = l;
	int b = n;

	while (a + 1 < b)
	{
		int c = (a + b) / 2;
		if (k > mas[c])
			a = c;
		else
			b = c;
	}
	if (mas[b] == k)
		return b;
	else
		return -1;
}

int main()
{
	srand(time(0));
	int* mas = new int[N];
	int K = rand() % N + 1;

	for (int i = 0; i < N; i++)
		mas[i] = rand()*rand()

	Timer A;
	for (int i = 0; i < M; i++)
	{
		BinarySearch(mas, 0, N - 1, K);
	}
	std::cout << "BinarySearch = " << A.elapsed() << std::endl;

	Timer B;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mas[j] == K)
			{
				break;
			}
	std::cout << "Search= " << B.elapsed() << std::endl;
	return 0;
}
