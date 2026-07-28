class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double toKelvin=celsius+273.15;
        double toFahrenheit=celsius*1.80+32.00;
        ans.push_back(toKelvin);
                ans.push_back(toFahrenheit);

        return ans;
    }
};