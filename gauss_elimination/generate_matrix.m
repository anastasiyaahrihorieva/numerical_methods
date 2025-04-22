for matIndex = 1:10
    A = zeros(10);
    condA = 10^matIndex; % Увеличиваем condA в 10 раз каждый раз
    mini = rand(1);
    maxi = condA * mini;  % Устанавливаем максимальное значение
    A(1, 1) = maxi;      
    A(2, 2) = mini;     

    for i = 3:10
        A(i, i) = mini + (maxi - mini) * rand(1);
    end

    % Заполнение верхней треугольной части матрицы
    for i = 1:10
        for j = (i + 1):10
            A(i, j) = rand(1);
        end
    end

    [Q, R] = qr(rand(10));
    A = Q.' * A * Q;

    % Запись матрицы в файл
    filename = sprintf('matrix_A_%d.txt', matIndex); 
    writematrix(A, filename, 'Delimiter', 'tab');
end
L = [1.4325 8.1302 3.1435 3.1324; 2.5402 5.1329 0 2.5465; 5.1430 2 3.1435 1.4354; 0 4.1324 4.2524 2.5465];
k = cond(L);