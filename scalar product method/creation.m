B = zeros(10);
V = zeros(1, 10);
for i = 1:10
    for j = i:10
        B(i, j) = rand(1);
        B(i, i) = i + 1; 
        V(1,i) = B(i, i);
    end
end
B(i, 10) = 50;
[Q, r] = qr(rand(10));
A = Q.' * B * Q;

[eigenvectors, eigenvalues] = eig(A);
eigenvalue_vector = diag(eigenvalues);

writematrix(A, 'matrix_A.txt', 'Delimiter', 'tab');
writematrix(eigenvalue_vector, 'eigenvalues.txt', 'Delimiter', 'tab');  
writematrix(max(eigenvalue_vector), 'max_eigenvalue.txt', 'Delimiter', 'tab');  
writematrix(V(:), 'xx.txt', 'Delimiter', 'tab');
writematrix(eigenvectors, 'eigenvectors.txt', 'Delimiter', 'tab');

[max_eigenvalue, idx] = max(eigenvalue_vector);

corresponding_eigenvector = eigenvectors(:, idx);
writematrix(corresponding_eigenvector, 'eig_vect_A.txt', 'Delimiter', 'tab');