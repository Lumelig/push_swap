/* Find max value in stack_b within a chunk range */
int	find_max_in_chunk(int *stack_b, int size_b, int lower, int upper)
{
	int	max_val;
	int	max_pos;
	int	j;

	max_val = -1;
	max_pos = -1;
	j = 0;
	while (j < size_b)
	{
		if (stack_b[j] >= lower && stack_b[j] < upper && stack_b[j] > max_val)
		{
			max_val = stack_b[j];
			max_pos = j;
		}
		j++;
	}
	return (max_pos);
}

/* Move value to top of stack_b and push to stack_a */
void	move_and_push(int *stack_a, int *stack_b, int *size_a, int *size_b,
		int max_pos)
{
	if (max_pos == 0)
	{
		// Already at the top, just push
	}
	else if (max_pos <= *size_b / 2)
	{
		while (max_pos-- > 0)
			rotate_b(stack_b, *size_b);
	}
	else
	{
		while (max_pos++ < *size_b)
			reverse_rotate_b(stack_b, *size_b);
	}
	push_a(stack_a, stack_b, size_a, size_b);
}

/* Push elements from chunk to stack_b */
void	push_chunk_to_b(int *stack_a, int *stack_b, int *size_a, int *size_b,
		int lower, int upper)
{
	int	j;
	int	initial_size;

	initial_size = *size_a;
	j = 0;
	while (j < initial_size)
	{
		if (*size_a > 0)
		{
			if (stack_a[0] >= lower && stack_a[0] < upper)
				push_b(stack_a, stack_b, size_a, size_b);
			else
				rotate_a(stack_a, *size_a);
		}
		j++;
	}
}

/* Push chunk elements back to stack_a in sorted order */
void	push_chunk_to_a(int *stack_a, int *stack_b, int *size_a, int *size_b,
		int lower, int upper)
{
	int	max_pos;

	while (*size_b > 0)
	{
		max_pos = find_max_in_chunk(stack_b, *size_b, lower, upper);
		if (max_pos == -1)
			break ;
		move_and_push(stack_a, stack_b, size_a, size_b, max_pos);
	}
}

/* Regular radix sort for smaller inputs */
void	regular_radix_sort(int *stack_a, int *stack_b, int size)
{
	int	size_a;
	int	size_b;
	int	max_bits;
	int	i;
	int	j;

	size_a = size;
	size_b = 0;
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (size_a > 0)
			{
				if (((stack_a[0] >> i) & 1) == 0)
					push_b(stack_a, stack_b, &size_a, &size_b);
				else
					rotate_a(stack_a, size_a);
			}
			j++;
		}
		while (size_b > 0)
			push_a(stack_a, stack_b, &size_a, &size_b);
		i++;
	}
}

/* First pass: push all chunks to stack_b */
void	push_all_chunks(int *stack_a, int *stack_b, int *size_a, int *size_b,
		int chunk_size, int num_chunks, int size)
{
	int	i;
	int	lower;
	int	upper;

	i = 0;
	while (i < num_chunks)
	{
		lower = i * chunk_size;
		if (i == num_chunks - 1)
			upper = size;
		else
			upper = (i + 1) * chunk_size;
		push_chunk_to_b(stack_a, stack_b, size_a, size_b, lower, upper);
		i++;
	}
}

/* Second pass: pull chunks back to stack_a in descending order */
void	pull_chunks_back(int *stack_a, int *stack_b, int *size_a, int *size_b,
		int chunk_size, int num_chunks, int size)
{
	int	i;
	int	lower;
	int	upper;

	i = num_chunks - 1;
	while (i >= 0)
	{
		lower = i * chunk_size;
		if (i == num_chunks - 1)
			upper = size;
		else
			upper = (i + 1) * chunk_size;
		push_chunk_to_a(stack_a, stack_b, size_a, size_b, lower, upper);
		i--;
	}
}

/* Optimized radix sort using chunking strategy */
void	optimized_radix_sort(int *stack_a, int *stack_b, int size)
{
	int	size_a;
	int	size_b;
	int	chunk_size;
	int	num_chunks;

	size_a = size;
	size_b = 0;
	index_stack(stack_a, size);
	if (size <= 50)
	{
		regular_radix_sort(stack_a, stack_b, size);
		return ;
	}
	if (size <= 100)
	{
		chunk_size = 25;
		num_chunks = 4;
	}
	else
	{
		chunk_size = size / 5;
		num_chunks = 5;
	}
	push_all_chunks(stack_a, stack_b, &size_a, &size_b,
		chunk_size, num_chunks, size);
	pull_chunks_back(stack_a, stack_b, &size_a, &size_b,
		chunk_size, num_chunks, size);
}