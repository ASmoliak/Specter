using System.Net;
using SpecterServer.Source.Utils;

namespace SpecterServer.Source
{
    public class EndpointManager
    {
        public delegate void EndpointUpdatedHandler(EndpointInfo endpoint);
        public event EndpointUpdatedHandler? OnEndpointUpdated;

        private readonly Dictionary<string, EndpointInfo> m_endpoints = new();
        private readonly Geolocator m_geolocator = new();

        public void AddOrUpdateEndpoint(HttpListenerRequest request)
        {
            var shortCountry = m_geolocator.IpToShortCountry(request.UserHostAddress);
            var longCountry = m_geolocator.IpToLongCountry(request.UserHostAddress);

            EndpointInfo args = new(request.Headers["hdserial"]!, request.UserHostAddress,
                                    request.Headers["osname"], request.Headers["machinename"],
                                    request.Headers["username"], request.Headers["uptime"], longCountry, shortCountry);

            m_endpoints[args.Uuid] = args;

            OnEndpointUpdated?.Invoke(args);
        }

        public EndpointInfo? FindEndpoint(string uuid)
        {
            m_endpoints.TryGetValue(uuid, out var endpointInfo);
            return endpointInfo;
        }
    }
}
