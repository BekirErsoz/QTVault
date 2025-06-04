int motor1_guc_degeri(int Roll_output_pid, int Pitch_output_pid, int Yaw_output_pid, int
throttle_kumanda_degeri){

motor1_guc_cikis = throttle_kumanda_degeri + Yaw_output_pid + Pitch_output_pid +
Roll_output_pid;

if(motor1_guc_cikis &gt; 1900) {motor1_guc_cikis = 1900;}
if(motor1_guc_cikis &lt; 1200) {motor1_guc_cikis = 1200;}
if(throttle_kumanda_degeri&lt;1200) motor1_guc_cikis=throttle_kumanda_degeri;

return motor1_guc_cikis;
}