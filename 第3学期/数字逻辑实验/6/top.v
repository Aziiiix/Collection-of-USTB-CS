//top.v

`timescale 1ns / 1ps

module top(input clk100mhz,
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

            output [3:0]pos,
            output [7:0]seg,

            output led_up1,
            output led_up2,
            output led_up3,
            output led_down4,
            output led_down3,
            output led_down2,
            output led_to1,
            output led_to2,
            output led_to3,
            output led_to4
            );

            wire[15:0]dataBus;//四位显示
            wire clk190hz, clk10000hz;

            clkDiv U1(clk100mhz, clk190hz, clk10000hz);//分频
            elevator U2(clk10000hz,
                        clk190hz,
                        reset,
                        key_up1,
                        key_up2,
                        key_up3,
                        key_down4,
                        key_down3,
                        key_down2,
                        key_to1,
                        key_to2,
                        key_to3,
                        key_to4,
                        led_up1,
                        led_up2,
                        led_up3,
                        led_down2,
                        led_down3,
                        led_down4,
                        led_to1,
                        led_to2,
                        led_to3,
                        led_to4,
                        dataBus
            );//电梯主模块
            segMsg U3(clk190hz, dataBus, pos, seg);//显示
endmodule

