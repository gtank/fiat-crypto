static void freeze(uint32_t out[12], const uint32_t in1[12]) {
  { const uint32_t x21 = in1[11];
  { const uint32_t x22 = in1[10];
  { const uint32_t x20 = in1[9];
  { const uint32_t x18 = in1[8];
  { const uint32_t x16 = in1[7];
  { const uint32_t x14 = in1[6];
  { const uint32_t x12 = in1[5];
  { const uint32_t x10 = in1[4];
  { const uint32_t x8 = in1[3];
  { const uint32_t x6 = in1[2];
  { const uint32_t x4 = in1[1];
  { const uint32_t x2 = in1[0];
  { uint32_t x24, uint8_t x25 = Op (Syntax.SubWithGetBorrow 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (0x0, Return x2, 0x3fffff);
  { uint32_t x27, uint8_t x28 = Op (Syntax.SubWithGetBorrow 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x25, Return x4, 0x1fffff);
  { uint32_t x30, uint8_t x31 = Op (Syntax.SubWithGetBorrow 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x28, Return x6, 0x1fffff);
  { uint32_t x33, uint8_t x34 = Op (Syntax.SubWithGetBorrow 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x31, Return x8, 0x3fffff);
  { uint32_t x36, ℤ x37 = Op (Syntax.SubWithGetBorrow 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) Syntax.TZ) (Return x34, Return x10, 0x3ff);
  { uint32_t x39, ℤ x40 = Op (Syntax.SubWithGetBorrow 21 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) Syntax.TZ) (Return x37, Return x12, 0x0);
  { uint32_t x42, ℤ x43 = Op (Syntax.SubWithGetBorrow 22 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) Syntax.TZ) (Return x40, Return x14, 0x0);
  { uint32_t x45, ℤ x46 = Op (Syntax.SubWithGetBorrow 21 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) Syntax.TZ) (Return x43, Return x16, 0x0);
  { uint32_t x48, ℤ x49 = Op (Syntax.SubWithGetBorrow 21 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) Syntax.TZ) (Return x46, Return x18, 0x0);
  { uint32_t x51, ℤ x52 = Op (Syntax.SubWithGetBorrow 22 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) Syntax.TZ) (Return x49, Return x20, 0x1);
  { uint32_t x54, uint8_t x55 = Op (Syntax.SubWithGetBorrow 21 Syntax.TZ (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x52, Return x22, 0x1ffc00);
  { uint32_t x57, uint8_t x58 = Op (Syntax.SubWithGetBorrow 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x55, Return x21, 0x1fffff);
  { uint32_t x59 = cmovznz32(x58, 0x0, 0xffffffff);
  { uint32_t x60 = (x59 & 0x3fffff);
  { uint32_t x62, uint8_t x63 = Op (Syntax.AddWithGetCarry 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (0x0, Return x24, Return x60);
  { uint32_t x64 = (x59 & 0x1fffff);
  { uint32_t x66, uint8_t x67 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x63, Return x27, Return x64);
  { uint32_t x68 = (x59 & 0x1fffff);
  { uint32_t x70, uint8_t x71 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x67, Return x30, Return x68);
  { uint32_t x72 = (x59 & 0x3fffff);
  { uint32_t x74, uint8_t x75 = Op (Syntax.AddWithGetCarry 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x71, Return x33, Return x72);
  { uint32_t x76 = (x59 & 0x3ff);
  { uint32_t x78, uint8_t x79 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x75, Return x36, Return x76);
  { uint32_t x81, uint8_t x82 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x79, Return x39, 0x0);
  { uint32_t x84, uint8_t x85 = Op (Syntax.AddWithGetCarry 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x82, Return x42, 0x0);
  { uint32_t x87, uint8_t x88 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x85, Return x45, 0x0);
  { uint32_t x90, uint8_t x91 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x88, Return x48, 0x0);
  { uint8_t x92 = ((uint8_t)x59 & 0x1);
  { uint32_t x94, uint8_t x95 = Op (Syntax.AddWithGetCarry 22 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x91, Return x51, Return x92);
  { uint32_t x96 = (x59 & 0x1ffc00);
  { uint32_t x98, uint8_t x99 = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x95, Return x54, Return x96);
  { uint32_t x100 = (x59 & 0x1fffff);
  { uint32_t x102, uint8_t _ = Op (Syntax.AddWithGetCarry 21 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x99, Return x57, Return x100);
  out[0] = x62;
  out[1] = x66;
  out[2] = x70;
  out[3] = x74;
  out[4] = x78;
  out[5] = x81;
  out[6] = x84;
  out[7] = x87;
  out[8] = x90;
  out[9] = x94;
  out[10] = x98;
  out[11] = x102;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
