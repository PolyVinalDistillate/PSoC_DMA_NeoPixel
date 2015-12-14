// ======================================================================
// NeoPixel.v generated from TopDesign.cysch
// 12/02/2015 at 09:54
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PANTHER 5
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 5
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 6
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 7
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 8
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 9
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 10
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 11
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4F 12
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4M 13
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 14
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 15
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 16
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 17
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 18
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 17
`define CYDEV_CHIP_REVISION_USED 0
`include "cypress.v"
/* ==================== Include Component Definitions ==================== */

// Component: Count7_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0\Count7_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0\Count7_v1_0.v"
`endif

module NeoPixDrv_UDB_v1_1 (
    input wire clock, 
    output wire DOut, 
    output wire Hungry
);

/* ==================== Wire and Register Declarations ==================== */
localparam [2:0] Idle = 3'b000;
localparam [2:0] GetData = 3'b001;
localparam [2:0] WaitHigh = 3'b010;
localparam [2:0] WaitLow = 3'b011;
localparam [2:0] ShiftData = 3'b100;
localparam S0 = 1'b0;
localparam S1 = 1'b1;
wire LoadCounter;
wire EnableCounter;
wire TimerActive;
wire ReloadPulsewidthCounters;
wire Timeout;
wire EnablePulseWidthCounters;
wire ShiftOut;
wire NoData;
wire CycleTimeout;
wire SpaceForData;
wire DPTH_d0_load;
wire DPTH_d1_load;
wire DPTH_f0_load;
wire DPTH_f1_load;
wire DPTH_route_si;
wire DPTH_route_ci;
wire  [2:0] DPTH_select;
wire BITCNT_en;
wire BITCNT_load;
wire BITCNT_reset;
wire  [6:0] BITCNT_count;
wire FinalBit;
wire ONTime_en;
wire ONTime_load;
wire ONTime_reset;
wire  [6:0] ONTime_count;
wire ONTimeDone;
wire OFFTime_en;
wire OFFTime_load;
wire OFFTime_reset;
wire  [6:0] OFFTime_count;
wire OFFTimeDone;
reg  [2:0] MainState;
reg CurrentBit;

/* ==================== Assignment of Combinatorial Variables ==================== */
assign DOut = (MainState == WaitHigh);
assign Hungry = (SpaceForData);
assign LoadCounter = (MainState == GetData);
assign EnableCounter = (MainState == ShiftData);
assign TimerActive = ((MainState == WaitHigh) | (MainState == WaitLow));
assign ReloadPulsewidthCounters = ((MainState == GetData) | (MainState == ShiftData));
assign Timeout = ((ONTimeDone & (CurrentBit == S1)) | (OFFTimeDone & (CurrentBit == S0)));
assign EnablePulseWidthCounters = (ReloadPulsewidthCounters | (MainState == WaitHigh));
assign DPTH_d0_load = (1'b0);
assign DPTH_d1_load = (1'b0);
assign DPTH_f0_load = (1'b0);
assign DPTH_f1_load = (1'b0);
assign DPTH_route_si = (1'b0);
assign DPTH_route_ci = (1'b0);
assign DPTH_select[0] = (MainState[0]);
assign DPTH_select[1] = (MainState[1]);
assign DPTH_select[2] = (MainState[2] | TimerActive);
assign BITCNT_en = (EnableCounter | LoadCounter);
assign BITCNT_load = (LoadCounter);
assign BITCNT_reset = (1'b0);
assign ONTime_en = (EnablePulseWidthCounters);
assign ONTime_load = (ReloadPulsewidthCounters);
assign ONTime_reset = (1'b0);
assign OFFTime_en = (EnablePulseWidthCounters);
assign OFFTime_load = (ReloadPulsewidthCounters);
assign OFFTime_reset = (1'b0);

/* ==================== DPTH (Width: 8) Instantiation ==================== */
parameter DPTH_dpconfig0 = 
{
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM0:  */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP___SL, `CS_A0_SRC___F0, `CS_A1_SRC___D1, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM1:  */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP___SL, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM2:  */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP___SL, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM3:  */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP___SL, `CS_A0_SRC__ALU, `CS_A1_SRC___D1, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM4:  */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0, `CS_SHFT_OP___SL, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM5:  */
    `CS_ALU_OP__DEC, `CS_SRCA_A1, `CS_SRCB_D0, `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC__ALU, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM6:  */
    `CS_ALU_OP__DEC, `CS_SRCA_A1, `CS_SRCB_D0, `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC__ALU, `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA, `CS_CMP_SEL_CFGA,  /*CFGRAM7:  */
    8'hFF, 8'h00, /* CFG9 */
    8'hFF, 8'hFF, /* CFG11-10 */
    `SC_CMPB_A1_D1, `SC_CMPA_A0_D1, `SC_CI_B_ARITH, `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL, `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI, `SC_SI_A_DEFSI, /* CFG13-12 */
    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'b0, `SC_SR_SRC_REG, `SC_FIFO1_BUS, `SC_FIFO0_BUS, `SC_MSB_ENBL, `SC_MSB_BIT7, `SC_MSB_NOCHN, `SC_FB_NOCHN, `SC_CMP1_NOCHN, `SC_CMP0_NOCHN, /* CFG15-14 */
    3'b000, `SC_FIFO_SYNC__ADD, 2'b000, `SC_FIFO1_DYN_OF, `SC_FIFO0_DYN_OF, `SC_FIFO_CLK1_POS, `SC_FIFO_CLK0_POS, `SC_FIFO_CLK__DP, `SC_FIFO_CAP_AX, `SC_FIFO_LEVEL, `SC_FIFO__SYNC, `SC_EXTCRC_DSBL, `SC_WRK16CAT_DSBL /* CFG17-16 */
};
cy_psoc3_dp8 #(
    .cy_dpconfig_a( DPTH_dpconfig0 ),
    .d0_init_a( 8'b00000000 ),
    .d1_init_a( 8'b00000000 ),
    .a0_init_a( 8'b00000000 ),
    .a1_init_a( 8'b00000000 ))
    DPTH(
        .clk( clock ),
        .cs_addr( DPTH_select ),
        .route_si( DPTH_route_si ),
        .route_ci( DPTH_route_ci ),
        .f0_load( DPTH_f0_load ),
        .f1_load( DPTH_f1_load ),
        .d0_load( DPTH_d0_load ),
        .d1_load( DPTH_d1_load ),
        .ce0(  ), 
        .cl0(  ), 
        .z0(  ), 
        .ff0(  ), 
        .ce1(  ), 
        .cl1(  ), 
        .z1( CycleTimeout ), 
        .ff1(  ), 
        .ov_msb(  ), 
        .co_msb(  ), 
        .cmsb(  ), 
        .so( ShiftOut ), 
        .f0_bus_stat( SpaceForData ), 
        .f0_blk_stat( NoData ), 
        .f1_bus_stat(  ), 
        .f1_blk_stat(  )
    );

/* ==================== State Machine: MainState ==================== */
always @ (posedge clock)
begin : Idle_state_logic
    case(MainState)
        Idle : 
        begin
            if (( !NoData ) == 1'b1)
            begin
                MainState <= GetData ;
            end
        end
        GetData : 
        begin
            if (( 1'b1 ) == 1'b1)
            begin
                MainState <= WaitHigh ;
            end
        end
        WaitHigh : 
        begin
            if (( Timeout ) == 1'b1)
            begin
                MainState <= WaitLow ;
            end
        end
        WaitLow : 
        begin
            if (( CycleTimeout ) == 1'b1)
            begin
                MainState <= ShiftData ;
            end
        end
        ShiftData : 
        begin
            if (( !FinalBit ) == 1'b1)
            begin
                MainState <= WaitHigh ;
            end
            else if (( FinalBit & !NoData ) == 1'b1)
            begin
                MainState <= GetData ;
            end
            else if (( FinalBit & NoData ) == 1'b1)
            begin
                MainState <= Idle ;
            end
        end
        default :
        begin
            MainState <= Idle;
        end
    endcase
end

/* ==================== State Machine: CurrentBit ==================== */
always @ (posedge clock)
begin : S0_state_logic
    case(CurrentBit)
        S0 : 
        begin
            if (( ((MainState == GetData) | (MainState == ShiftData)) & ShiftOut ) == 1'b1)
            begin
                CurrentBit <= S1 ;
            end
        end
        S1 : 
        begin
            if (( ((MainState == GetData) | (MainState == ShiftData)) & !ShiftOut ) == 1'b1)
            begin
                CurrentBit <= S0 ;
            end
        end
        default :
        begin
            CurrentBit <= S0;
        end
    endcase
end

/* ==================== BITCNT ==================== */
    Count7_v1_0 BITCNT (
        .en(BITCNT_en),
        .load(BITCNT_load),
        .clock(clock),
        .reset(BITCNT_reset),
        .cnt(BITCNT_count),
        .tc(FinalBit));
    defparam BITCNT.EnableSignal = 1;
    defparam BITCNT.LoadSignal = 1;

/* ==================== ONTime ==================== */
    Count7_v1_0 ONTime (
        .en(ONTime_en),
        .load(ONTime_load),
        .clock(clock),
        .reset(ONTime_reset),
        .cnt(ONTime_count),
        .tc(ONTimeDone));
    defparam ONTime.EnableSignal = 1;
    defparam ONTime.LoadSignal = 1;

/* ==================== OFFTime ==================== */
    Count7_v1_0 OFFTime (
        .en(OFFTime_en),
        .load(OFFTime_load),
        .clock(clock),
        .reset(OFFTime_reset),
        .cnt(OFFTime_count),
        .tc(OFFTimeDone));
    defparam OFFTime.EnableSignal = 1;
    defparam OFFTime.LoadSignal = 1;

endmodule

// NeoPixel_v1_2(CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=NeoPixel_v1_2, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=NP, CY_INSTANCE_SHORT_NAME=NP, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=2, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP1, INSTANCE_NAME=NP, )
module NeoPixel_v1_2_0 (
    DOut,
    Clock);
    output      DOut;
    input       Clock;


          wire  Net_13;
          wire  Net_12;
          wire  Net_3;

    NeoPixDrv_UDB_v1_1 Neo (
        .clock(Clock),
        .DOut(DOut),
        .Hungry(Net_3));


	cy_dma_v1_0
		#(.drq_type(2'b01))
		DMA
		 (.drq(Net_3),
		  .trq(1'b0),
		  .nrq(Net_13));




endmodule

// top
module top ;

          wire  Net_29;
          wire  Net_58;
          wire  Net_49;

	wire [0:0] tmpOE__Data_net;
	wire [0:0] tmpFB_0__Data_net;
	wire [0:0] tmpIO_0__Data_net;
	wire [0:0] tmpINTERRUPT_0__Data_net;
	electrical [0:0] tmpSIOVREF__Data_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Data
		 (.oe(tmpOE__Data_net),
		  .y({Net_58}),
		  .fb({tmpFB_0__Data_net[0:0]}),
		  .io({tmpIO_0__Data_net[0:0]}),
		  .siovref(tmpSIOVREF__Data_net),
		  .interrupt({tmpINTERRUPT_0__Data_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Data_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("2a7014c5-2cde-45dd-9042-d5c4cf34ad7a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("78125000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_49));


    NeoPixel_v1_2_0 NP (
        .Clock(Net_49),
        .DOut(Net_58));



endmodule

