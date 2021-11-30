        Game Caro
    
input:
    - bắt đầu nhập kích thước ô Caro
        + có giới hạn kích thước
        + hoặc không giới hạn
    - hai người chơi chọn X hoặc O

    - 2 người chơi nhập lần lượt theo dạng một ký tự O hoặc X đã chọn và hai chữ số trong khoảng cho phép
        + 2 sô nguyên là tọa độ ô muốn đánh phải ở trong bàn cờ và chưa được đánh
    
xử lý:
    - mỗi lần người chơi nhập input, in ra màn hình bàn cờ hiện tại.


    - sau kiểm tra xem bên nào thắng hoặc 2 bên hòa nhau:
        
        + nếu bàn cờ không còn ô trống thì 2 người hòa

        + điều kiện thắng: nếu bên nào điền được 5 ký tự giống nhau liên tiếp theo hàng ngang(dọc) hoặc hàng chéo

            * tối ưu điều kiện thắng: nếu người chơi có 2 hàng (ngang hoặc dọc hoặc chéo) đã đủ 4 ký tự liền nhau mà giao nhau  thì người chơi đó thắng 
    
    - nếu có in ra màn hình thông báo kết quả và câu hỏi tiếp tục chơi :
        
        + chọn chơi mới để reset lại dữ liệu bàn cờ
        
        + hoặc chọn chơi tiếp với kích thước bàn cờ cũ

    - nếu không 2 bên tiếp tục chơi

mô tả bàn cờ:

    - bàn cờ là ma trận vuông được đánh số từ 1
    
    - in ra màn hình sẽ hiển thị số hàng và cột đánh từ 1, tiếp đó là các ô trong bàn cờ


