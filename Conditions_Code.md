                Cách kiểm tra ai thắng ai thua - Cờ Caro

1. Ý tưởng

    - Ta sẽ đếm các nước cờ liên tiếp nhau theo hàng, cột, đường chéo. Nếu đủ 5 nước liên thiếp thì sẽ dành chiến thắng. 

    - Nếu chưa có ai tới 5 mà bàn cờ đã được đánh hết thì hai người chơi hòa nhau.

2. Ý tưởng thuật toán

    - Ta sẽ dùng 4 mảng 2 chiều có cùng độ lớn với bàn cờ để lưu các nước liên tiếp theo hàng, cột, đường chéo chính và đường chéo phụ.

    - ta sẽ khởi tạo biến đếm là 1, nếu ô tiếp theo vẫn mang giá trị giống với ô trước thì sẽ tăng lên 1, nếu không ta gán biến đếm là 0.

3. Độ phức tạp thuật toán

    - mỗi hàm kiểm tra có độ phức tạp là O(n^2)
    - nhưng với kích thước nhỏ thì O(n^2) vẫn hiệu quả.