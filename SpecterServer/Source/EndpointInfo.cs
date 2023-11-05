namespace SpecterServer.Source;

public class EndpointInfo
{
    public EndpointInfo(string uuid, string? userHostAddress, 
                        string? operatingSystem, string? machineName,
                        string? username, string? uptime, string country, string countryShort)
    {
        Uuid = uuid;
        UserHostAddress = userHostAddress;
        OperatingSystem = operatingSystem;
        MachineName = machineName;
        Username = username;
        Uptime = uptime;
        Country = country;
        CountryShort = countryShort;
    }

    public string Uuid { get; }
    public string? UserHostAddress { get; }
    public string? OperatingSystem { get; }
    public string? MachineName { get; }
    public string? Username { get; }
    public string? Uptime { get; }
    public string? Country { get; }
    public string? CountryShort { get; }
}