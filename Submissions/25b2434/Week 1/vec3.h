class Vec3 {
    public: 
        float x , y , z ; 
        Vec3(){
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
        Vec3(float x_val , float y_val, float z_val ){
            x = x_val;
            y = y_val;
            z = z_val;
        }
        Vec3 operator+(const Vec3 &V2) const{
            float n_x = x + V2.x;
            float n_y = y + V2.y;
            float n_z = z + V2.z;
            return Vec3(n_x, n_y , n_z);

        }
        Vec3 operator-(const Vec3 &V2) const{
            float n_x = x - V2.x;
            float n_y = y - V2.y;
            float n_z = z - V2.z;
            return Vec3(n_x, n_y , n_z);
        }
        Vec3 operator*(float a) {
            float n_x = x * a ;
            float n_y = y * a ;
            float n_z = z * a ;
            return Vec3(n_x, n_y , n_z);
        }
        friend Vec3 operator*(float a, const Vec3& vec) {
            return Vec3(vec.x * a, vec.y * a, vec.z * a);
        }
    

        
        Vec3 operator/(float a){
            float n_x = x / a ;
            float n_y = y / a ;
            float n_z = z / a ;
            return Vec3(n_x, n_y , n_z);
        }
        Vec3 operator-(){
            float n_x = x * -1 ;
            float n_y = y * -1 ;
            float n_z = z * -1 ;
            return Vec3(n_x, n_y , n_z);
        }
        float length(){
            return sqrt(x*x + y*y + z*z);
        }
        Vec3 unit(){
            float length = sqrt(x*x + y*y + z*z);
            float n_x = x / length ;
            float n_y = y / length ;
            float n_z = z / length ;
            return Vec3(n_x, n_y , n_z);
        }
        float dot(const Vec3& other){
            float dp = x*other.x + y*other.y + z*other.z;
            return dp;
        }
        float& operator[](int i){
            if(i == 0) return x;
            else if(i == 1) return y;
            else if(i == 2) return z;
        }
        Vec3 cross(const Vec3& other){
            float n_x = (y* other.z) - (z * other.y); 
            float n_y = -(x* other.z) + (z* other.x);
            float n_z = (x* other.y) - (y * other.x);
            return Vec3(n_x , n_y, n_z);
        }
        Vec3 reflect(const Vec3& normal){
            Vec3 n = normal;
            Vec3 unit_normal = n.unit();
            float dot = Vec3(x , y, z).dot(unit_normal);
            return Vec3(x , y , z) -  (unit_normal) * 2 * dot;
        }
        Vec3 refract(const Vec3& normal , float refractive_index){
            Vec3 I = Vec3(x, y, z).unit();
            Vec3 n = normal;
            Vec3 N = n.unit();

            float cos_i = I.dot(N);
            
            float eta;
            Vec3 target_normal;

            if (cos_i < 0.0f) {
                cos_i = -cos_i;
                eta = 1.0f / refractive_index;
                target_normal = N;
            } else {
                cos_i = cos_i; 
                eta = refractive_index;
                target_normal = -N;
            }

            float k = 1.0f - eta * eta * (1.0f - cos_i * cos_i);

            if (k < 0.0f) {
                return Vec3(0.0f, 0.0f, 0.0f); 
            }

            return I * eta + target_normal * (eta * cos_i - sqrt(k));
        }

};