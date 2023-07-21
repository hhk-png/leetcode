int MakeChangeCore(int n, int denom)
{
	int next_denom = 0;
	switch (denom)
	{
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}

	int res = 0;
	for (int i = 0; i*denom <= n; i++)
		res += MakeChangeCore(n - i * denom, next_denom);

	return res;

}

int MakeChange(int n)
{
	if (n <= 0)
		return -1;
	return MakeChangeCore(n, 25);
}