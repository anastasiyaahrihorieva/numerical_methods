% D = zeros(10);
% B = randi(10, 10, 10);
% det_curr = 1;
% 
% for i=1:9
%     D(i, i) = rand(1);
%     det_curr = det_curr*D(i, i);
% end
% D(10,10) = 10 / det_curr
% % det(D);
% B2 = inv(B);
% A =B2*D*B;
% det(A);
% 
% writematrix(A,'M_tab.txt','WriteMode','append','Delimiter','tab');

% Инициализация матрицы B, детерминантов и собственных значений
B = zeros(10);  
det_all = zeros(1, 10); 
det_curr = 1; 
own_values = zeros(1, 2);  

% Заполнение диагонали матрицы B случайными значениями
for i = 1:9
    B(i, i) = rand(1) + 1;  
    det_curr = det_curr * B(i, i);  
end
B(10, 10) = 10 / det_curr;  

own_values(1, 1) = max(diag(B));  
own_values(1, 2) = min(diag(B));  


[Q, r] = qr(rand(10));  
A = Q.' * B * Q; 


writematrix(A, 'matrix_A_1.txt', 'Delimiter', 'tab');
writematrix(own_values, 'A_1.txt', 'WriteMode', 'append', 'Delimiter', 'tab');

fileID = fopen('det_all.txt', 'w'); 


for i = 1:10
    B(i, i) = B(i, i) / 10;  
    A = Q.' * B * Q;  

   
    if size(A, 1) == size(A, 2) 
        det_all(i) = det(A);  
        fprintf(fileID, '%.10f\n', det_all(i));  

 
        own_values(1, 1) = max(diag(B));  
        own_values(1, 2) = min(diag(B));  

        writematrix(A, ['matrix_A_' num2str(i + 1) '.txt'], 'Delimiter', 'tab'); 
        writematrix(own_values, ['A_' num2str(i + 1) '.txt'], 'WriteMode', 'append', 'Delimiter', 'tab');
    else
        warning('Матрица A имеет неверные размеры.');
    end
end

fclose(fileID); 