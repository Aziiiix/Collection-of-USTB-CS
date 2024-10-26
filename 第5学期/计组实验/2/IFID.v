`timescale 1ns / 1ps

`include "bus.v"

module IFID(
  input               clk,
  input               rst,
  input               stall_current_stage,
  input               stall_next_stage,
  input   [`ADDR_BUS] addr_in,
  input   [`INST_BUS] inst_in,
  output reg  [`ADDR_BUS] addr_out,
  output reg  [`INST_BUS] inst_out
);

  always @(posedge clk) begin
    if (rst) begin
      addr_out <= 0;
      inst_out <= 0;
    end
    else begin
      addr_out <= addr_in;
      inst_out <= inst_in;
    end
  end


  // PipelineDeliver #(`ADDR_BUS_WIDTH) ff_addr(
  //   clk, rst,
  //   stall_current_stage, stall_next_stage,
  //   addr_in, addr_out
  // );

  // PipelineDeliver #(`INST_BUS_WIDTH) ff_inst(
  //   clk, rst,
  //   stall_current_stage, stall_next_stage,
  //   inst_in, inst_out
  // );

endmodule // IFID
