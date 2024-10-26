//elevator.v

`timescale 1ns / 1ps

module elevator(input clk10000hz,
input clk190hz,
input reset,
input key_up1,
input key_up2,
input key_up3,
input key_down4,
input key_down3,
input key_down2,
input key_to1,
input key_to2,
input key_to3,
input key_to4,
output reg led_up1,
output reg led_up2,
output reg led_up3,
output reg led_down2,
output reg led_down3,
output reg led_down4,
output reg led_to1,
output reg led_to2,
output reg led_to3,
output reg led_to4,
output reg [15:0]dataBus
);

parameter _11 = 4'b0000,//1-> 1
          _12 = 4'b0001,//1-> 2
          _22 = 4'b0010,//2-> 2
          _21 = 4'b0011,//2-> 1
          _23 = 4'b0100,//2-> 3
          _33 = 4'b0101,//3-> 3
          _32 = 4'b0110,//3-> 2
          _34 = 4'b0111,//3-> 4
          _44 = 4'b1000,//4-> 4
          _43 = 4'b1001,//4-> 3

          time_wait = 2000,//楼层停留时间
          time_go = 200,//楼层移动所需时间

          up = 4'b1010,//上升=10
          down = 4'b1011,//下降=11
          Wait = 4'b1100;//等待=12

reg[3:0] state = _11;//当前状态
reg[3:0]next_state = _11;//下一状态
reg door = 1;//电梯门
reg [3:0]direction = Wait;//电梯移动方向
reg[2:0]floor = 1;//楼层
reg[20:0]counter = 0;//计数器
//初始化各参数

reg up1 = 0,
    up2 = 0,
    up3 = 0,
    down2 = 0,
    down3 = 0,
    down4 = 0,
    to1 = 0,
    to2 = 0,
    to3 = 0,
    to4 = 0;
//初始化楼层控制置零

always@(posedge clk10000hz)
begin
    if(reset)//异步重置
    begin
        state <= _11;
        next_state <= _11; //重置默认楼层为1
    end
    else
        state <= next_state;//状态更新
    
    if(state == _11 || state == _12)//楼层判定
        floor <= 1;//1->1 1->2时显示楼层1
    else if(state == _21 || state == _22 || state == _23)
        floor <= 2;//2->1 2->2 2->3时显示楼层2
    else if(state == _32 || state == _33 || state == _34)
        floor <= 3;//3->2 3->3 3->4时显示楼层3
    else if(state == _43 || state == _44)
        floor <= 4;//4->3 4->4时显示楼层4
    else
        floor <= 5;//异常状态楼层5（可供异常状态判断，没啥用）
    
    if(state == _11 || state == _22 || state == _33 || state == _44)//当前楼层则开门
        door <= 1;
    else
        door <= 0;//楼层移动中关门
        
    dataBus[3:0] <= door; //数码管右一
    dataBus[7:4] <= direction;//数码管右二
    dataBus[11:8] <= floor;//数码管左二
    dataBus[15:12] <= state;//数码管左一
    
    led_up1 <= up1;
    led_up2 <= up2;
    led_up3 <= up3;
    led_down4 <= down4;
    led_down3 <= down3;
    led_down2 <= down2;
    led_to1 <= to1;
    led_to2 <= to2;
    led_to3 <= to3;
    led_to4 <= to4; 
    //LED指示灯状态更新

end

always@(posedge clk190hz)//板子输入转化内部信号
begin
    if(key_up1 && state != _11)//不在1楼时，电梯外部，1楼按上，则发出up1信号
        up1 <= 1;else;
    if(key_up2 && state != _22)//不在2楼时，电梯外部，2楼按上，则发出up2信号
        up2 <= 1;else;
    if(key_up3 && state != _33)//不在3楼时，电梯外部，3楼按上，则发出up3信号
        up3 <= 1;else;

    if(key_down2 && state != _22)//不在2楼时，电梯外部，2楼按下，则发出down2信号
        down2 <= 1;else;
    if(key_down3 && state != _33)//不在3楼时，电梯外部，3楼按下，则发出down3信号
        down3 <= 1;else;
    if(key_down4 && state != _44)//不在4楼时，电梯外部，4楼按下，则发出down4信号
        down4 <= 1;else;

    if(key_to1 && state != _11)//不在1楼时，电梯内部，需要前往1楼，则发出to1信号
        to1 <= 1;else;
    if(key_to2 && state != _22)//不在2楼时，电梯内部，需要前往2楼，则发出to2信号
        to2 <= 1;else;
    if(key_to3 && state != _33)//不在3楼时，电梯内部，需要前往3楼，则发出to3信号
        to3 <= 1;else;
    if(key_to4 && state != _44)//不在4楼时，电梯内部，需要前往4楼，则发出to4信号
        to4 <= 1;else;
    
    case(state)
        _11:
        begin
            if(counter < time_wait)//开门时间判定
            begin//开门
                direction = up;//方向上升
                counter <= counter + 1;//计时
                next_state = _11;
                up1 <= 0;
                to1 <= 0;//up1.to1灯灭
            end
            
            else
            begin//关门
                if(to2 || to3 || to4 || up2 || up3 || down4 || down3 || down2)//其他状态
                begin
                    counter <= 0;//计时置零
                    next_state <= _12;//进入1->2状态
                    direction <= up;//上升
                end
                
                else
                begin//没有其他状态
                    next_state <= _11;//保持11状态
                    direction <= Wait;//方向等待
                end
            end
        end
        
        _12:
        begin
            if(counter < time_go)//上升时间判定
            begin//仍在上升
                counter <= counter + 1;
                next_state <= _12;
                direction <= up;//计时器+ 保持状态和方向
            end
            
            else
            begin
                if(up2 || to2 || down2)//判断2楼停留与否
                begin//需要停留
                    next_state <= _22;//进入状态2->2
                    counter <= 0;//计数置零
                end
                
                else if(up3 || to3 || to4 || down4 || down3)//不需要停留2楼
                begin
                    next_state <= _23;//进入状态2->3
                    counter <= 0;//计数置零
                end

               else;
            end
        end
        
        _22:
        begin
            if(counter < time_wait)//功能与11相同
            begin
                to2 <= 0;
                up2 <= 0;
                down2 <= 0;
                next_state <= _22;
                counter <= counter + 1;
            end
            
            else
            begin
                case(direction)//方向判断
                    up://方向向上
                    begin
                        if(to3 || up3 || down3 || to4 || down4)//优先判断是否有上方楼层信号
                        begin
                            next_state <= _23;//进入状态2->3
                            counter <= 0;
                        end
                        
                        else if(up1 || to1)//其次判断是否有下方楼层信号
                        begin
                            next_state <= _21;//进入状态2->1
                            counter <= 0;
                        end
                        
                        else
                        begin//无上下方楼层信号，进入等待
                            direction <= Wait;
                        end
                    end
                    
                    down://方向向下
                    begin
                        if(to1 || up1)//优先判断是否有下方楼层信号
                        begin
                            next_state <= _21;
                            counter <= 0;
                        end
                        
                        else if(to3 || up3 || down3 || to4 || down4)//其次判断是否有上方楼层信号
                        begin
                            next_state <= _23;
                            counter <= 0;
                        end
                        
                       else//无上下方楼层信号，进入等待
                           direction <= Wait;
                    end
                    
                    Wait://方向等待
                    begin
                        if(to1 || up1)//优先判断是否有上方楼层信号
                        begin
                            next_state <= _21;
                            counter <= 0;
                        end
                        
                        else if(to3 || up3 || down3 || to4 || down4)//其次判断是否有下方楼层信号
                        begin
                            next_state <= _23;
                            counter <= 0;
                        end
                        
                       else//无上下方楼层信号，进入等待
                           direction <= Wait;
                    end
                    default;
                endcase
            end
        end
        
        _23://功能类同12
        begin
            if(counter < time_go)
            begin
                counter <= counter + 1;
                direction <= up;
                next_state <= _23;
            end
            
            else
            begin
                if(to3 || up3 || down3)
                begin
                    next_state <= _33;
                    counter <= 0;
                end
                
                else if(to4 || down4)
                begin
                    next_state <= _34;
                    counter <= 0;
                end
                
                else;
            end
        end
        
        _33://功能类同22
        begin
            if(counter < time_wait)
            begin
                up3 <= 0;
                down3 <= 0;
                to3 <= 0;
                next_state <= _33;
                counter <= counter + 1;
            end
            
            else
            begin
                case(direction)
                    up:
                    begin
                        if(to4 || down4)
                        begin
                            next_state <= _34;
                            counter <= 0;
                        end
                        else if(up1 || to1 || up2 || down2 || to2)
                        begin
                            next_state <= _32;
                            counter <= 0;
                        end
                        else
                        begin
                            direction <= Wait;
                        end
                    end
                    down:
                    begin
                        if(up1 || to1 || up2 || to2 || down2)
                        begin
                            next_state <= _32;
                            counter <= 0;
                        end
                        
                        else if(to4 || down4)
                        begin
                            next_state <= _34;
                            counter <= 0;
                        end
                        
                        else
                        begin
                            direction <= Wait;
                        end
                        
                    end
                    Wait:
                    begin
                        if(to4 || down4)
                        begin
                            next_state <= _34;
                            counter <= 0;
                        end
                        
                        else if(up1 || to1 || up2 || down2 || to2)
                        begin
                            next_state <= _32;
                            counter <= 0;
                        end
                        
                        else
                        begin
                            direction <= Wait;
                        end
                    end
                    default;
                endcase
            end
        end
        
        _34:
        begin
            if(counter < time_go)
            begin
                direction <= up;
                counter <= counter + 1;
                next_state <= _34;
            end
            
            else
            begin
                counter <= 0;
                next_state <= _44;
            end
        end
        
        _44:
        begin
            if(counter < time_wait)
            begin
                counter <= counter + 1;
                to4 <= 0;
                down4 <= 0;
                next_state <= _44;
                direction = down;
            end
            
            else
            begin
                if(up1 || to1 || up2 || down2 || to2 || up3 || down3 || to3)//判断是否有下方楼层信号
                begin
                    counter <= 0;
                    next_state <= _43;
                end
                else
                begin
                    direction <= Wait;
                end
            end
        end
        
        _43:
        begin
            if(counter < time_go)
            begin
                counter <= counter + 1;
                next_state <= _43;
                direction <= down;
            end
            
            else
            begin
                if(to3 || down3 || up3)//优先判断是否需要停留3楼
                begin//停留
                    next_state <= _33;
                    counter <= 0;
                end
                
                else if(up1 || to1 || up2 || down2 || to2)//不需要停留
                begin
                    next_state <= _32;//进入3->2
                    counter <= 0;
                end
                
                else;
            end
        end
        
        _32:
        begin
            if(counter < time_go)
            begin
                counter <= counter + 1;
                next_state <= _32;
                direction <= down;
            end
            
            else
            begin
                if(down2 || to2 || up2)//优先判断是否需要停留2楼
                begin
                    counter <= 0;
                    next_state <= _22;
                end
                
                else if(up1 || to1)//不需要停留2楼
                begin
                    counter <= 0;
                    next_state <= _21;
                end
                
                else;
            end
        end
        
        _21:
        begin
            if(counter < time_go)
            begin
                counter <= counter + 1;
                next_state <= _21;
                direction <= down;
            end
            
            else
            begin
                counter <= 0;
                next_state <= _11;
            end
        end
        default;
    endcase
end  
endmodule
